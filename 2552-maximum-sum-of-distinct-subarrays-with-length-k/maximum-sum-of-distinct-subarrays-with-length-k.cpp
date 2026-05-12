class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        long long sum = 0;
        long long maxi = 0;

        int i = 0;
        int j = 0;

        while (j < nums.size()) {

            sum += nums[j];
            mp[nums[j]]++;

            // window size becomes greater than k
            if (j - i + 1 > k) {

                sum -= nums[i];

                mp[nums[i]]--;

                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                i++;
            }

            // valid window of size k
            if (j - i + 1 == k) {

                // all elements distinct
                if (mp.size() == k) {
                    maxi = max(maxi, sum);
                }
            }

            j++;
        }

        return maxi;
    }
};