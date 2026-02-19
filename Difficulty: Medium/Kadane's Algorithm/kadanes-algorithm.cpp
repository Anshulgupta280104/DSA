class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();    
        vector<int> maxarr(n);
        
        maxarr[0] = arr[0];
        int maxSum = maxarr[0];
        
        for(int i = 1; i < n; i++){
            maxarr[i] = max(arr[i], maxarr[i-1] + arr[i]);
            maxSum = max(maxSum, maxarr[i]);
        }
        
        return maxSum;
    }
};
