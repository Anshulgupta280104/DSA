class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        int N = nums.size();

        for(int i = 0; i < N; i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else
            {
                if(candidate == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return candidate;
    }
};