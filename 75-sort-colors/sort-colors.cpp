class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        // Count 0s, 1s, 2s
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        // Fill 0s
        int index = 0;

        for(int i = 0; i < count0; i++)
            nums[index++] = 0;

        // Fill 1s
        for(int i = 0; i < count1; i++)
            nums[index++] = 1;

        // Fill 2s
        for(int i = 0; i < count2; i++)
            nums[index++] = 2;
    }
};
