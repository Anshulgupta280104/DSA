class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            // make mid even
            if (mid % 2 == 1) {
                mid--;
            }

            // pair is valid, single element is on right
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            }
            else {
                // broken pair, single element is on left (or mid itself)
                h = mid;
            }
        }

        return nums[l];
    }
};