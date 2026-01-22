class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        long long mid;   // use long long to avoid overflow
        int ans = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;          // possible answer
                start = mid + 1;    // search right part
            }
            else {
                end = mid - 1;      // search left part
            }
        }

        return ans;  // floor of sqrt(x)
    }
};
