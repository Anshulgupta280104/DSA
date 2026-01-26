class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        
        int n = arr.size();
        int left = 0;
        int sum = 0;
        
        for(int right = 0; right < n; right++) {
            
            sum += arr[right];   // expand window
            
            // shrink window if sum > target
            while(sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            // found answer
            if(sum == target) {
                return {left + 1, right + 1}; // 1-based index
            }
        }
        
        return {-1};
    }
};
