class Solution {
public:
    int singleNumber(vector<int>& nums) {
            int n = nums.size();
        int sing = nums[0];
        for(int i=1; i<n;i++)
        {
            sing =sing ^ nums[i];
        }
        return sing;
    }
};