class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element and use two pointers
        for(int i = 0; i < n - 2; i++)
        {
            // Skip duplicate elements
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int start = i + 1;
            int end = n - 1;

            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];

                if(sum == 0)
                {
                    result.push_back({nums[i], nums[start], nums[end]});

                    start++;
                    end--;

                    // Skip duplicates
                    while(start < end && nums[start] == nums[start-1])
                        start++;

                    while(start < end && nums[end] == nums[end+1])
                        end--;
                }
                else if(sum < 0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }

        return result;
    }
};
