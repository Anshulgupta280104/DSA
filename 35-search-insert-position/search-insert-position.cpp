class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;   // target found
            }
            else if (nums[mid] < target) {
                low = mid + 1;   // move right
            }
            else {
                high = mid - 1;  // move left
            }
        }

        // if not found, low is the correct insert position
        return low;
    }
};
