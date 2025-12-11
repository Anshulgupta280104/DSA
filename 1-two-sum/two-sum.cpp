class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value → index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // If complement exists in map, return the pair
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Otherwise store current value with the index
            mp[nums[i]] = i;
        }

        return {}; // Should never happen due to constraints
    }
};
