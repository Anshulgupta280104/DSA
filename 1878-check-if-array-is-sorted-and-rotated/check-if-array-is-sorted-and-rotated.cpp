class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Check if current element is greater than the next element
            // Use (i + 1) % n to handle the wrap-around back to index 0
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // A sorted and rotated array can have at most one "drop"
        return count <= 1;
    }
};