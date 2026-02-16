class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int len=INT_MIN;
        int n=0;
        while(r<nums.size()){
            if(nums[r]==0) n++;
            if(n>k){
                if(nums[l]==0) n--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};