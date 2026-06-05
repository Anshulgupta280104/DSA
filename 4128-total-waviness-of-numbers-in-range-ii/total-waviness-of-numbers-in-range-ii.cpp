class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][2][3][11][11];
    bool vis[20][2][3][11][11];

    Node dfs(int pos, int tight, int lenState, int last1, int last2) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][lenState][last1][last2]) {
            return dp[pos][tight][lenState][last1][last2];
        }

        vis[pos][tight][lenState][last1][last2] = true;

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; d++) {
            int ntight = (tight && d == limit);

            if (lenState == 0) {
                // Number has not started yet
                if (d == 0) {
                    Node nxt = dfs(pos + 1, ntight, 0, 10, 10);
                    totalCnt += nxt.cnt;
                    totalSum += nxt.sum;
                } else {
                    Node nxt = dfs(pos + 1, ntight, 1, d, 10);
                    totalCnt += nxt.cnt;
                    totalSum += nxt.sum;
                }
            } else if (lenState == 1) {
                Node nxt = dfs(pos + 1, ntight, 2, last1, d);
                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
            } else {
                // We already have at least 2 digits.
                int add = 0;

                int a = last1; // digit i-2
                int b = last2; // digit i-1

                if ((b > a && b > d) || (b < a && b < d))
                    add = 1;

                Node nxt = dfs(pos + 1, ntight, 2, b, d);

                totalCnt += nxt.cnt;
                totalSum += nxt.sum + nxt.cnt * 1LL * add;
            }
        }

        return dp[pos][tight][lenState][last1][last2] =
                   {totalCnt, totalSum};
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        Node res = dfs(0, 1, 0, 10, 10);
        return res.sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};