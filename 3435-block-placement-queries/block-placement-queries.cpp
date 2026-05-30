class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;

        for (auto &q : queries) {
            mx = max(mx, q[1]);
        }

        vector<int> seg(4 * (mx + 5), 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int idx, int val) -> void {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid)
                self(self, node * 2, l, mid, idx, val);
            else
                self(self, node * 2 + 1, mid + 1, r, idx, val);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {
            if (ql > r || qr < l) return 0;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) / 2;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        set<int> obstacles = {0, mx};

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        int previous = 0;

        for (int pos : obstacles) {
            update(update, 1, 0, mx, pos, pos - previous);
            previous = pos;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            if (queries[i][0] == 1) {

                int x = queries[i][1];

                auto it = obstacles.find(x);

                int right = *std::next(it);
                int left = *std::prev(it);

                update(update, 1, 0, mx, right, right - left);

                obstacles.erase(it);
            }
            else {

                int x = queries[i][1];
                int sz = queries[i][2];

                auto it = obstacles.upper_bound(x);

                int rightObstacle = *std::prev(it);

                int bestGap = query(query, 1, 0, mx, 0, rightObstacle);

                bool canPlace =
                    max(bestGap, x - rightObstacle) >= sz;

                ans.push_back(canPlace);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};