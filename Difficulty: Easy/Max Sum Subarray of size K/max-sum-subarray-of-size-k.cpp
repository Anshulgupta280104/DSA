class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int sum = 0;
        int maxi = 0;

        int n = arr.size();

        // First window
        for(int i = 0; i < k; i++) {
            sum = sum + arr[i];
        }

        maxi = max(maxi, sum);

        // Sliding window
        for(int i = k; i < n; i++) {

            sum = sum + arr[i];
            sum = sum - arr[i - k];

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};