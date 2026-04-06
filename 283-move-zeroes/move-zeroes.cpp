class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            // If current element is 0
            if(nums[i] == 0) {
                
                // Find next non-zero element
                int j = i + 1;
                while(j < n && nums[j] == 0) {
                    j++;
                }

                // If found non-zero, swap
                if(j < n) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};