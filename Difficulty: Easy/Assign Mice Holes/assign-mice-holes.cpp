class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        
        // Step 1: sort both
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int n = mices.size();
        int maxTime = 0;

        // Step 2: match ith mouse with ith hole
        for(int i = 0; i < n; i++)
        {
            int time = abs(mices[i] - holes[i]);
            maxTime = max(maxTime, time);
        }

        return maxTime;
    }
};
