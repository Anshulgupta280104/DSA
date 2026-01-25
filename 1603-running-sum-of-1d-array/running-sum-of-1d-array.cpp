class Solution {
public:
    
    void helper(vector<int>& nums, int i) {
        if(i == nums.size())   // base case
            return;
        
        nums[i] += nums[i-1]; // running sum
        
        helper(nums, i+1);    // recursive call
    }
    
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums;
        
        helper(nums, 1);  // start from index 1
        
        return nums;
    }
};
