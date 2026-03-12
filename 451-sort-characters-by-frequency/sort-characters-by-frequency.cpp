class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> mp;

        // Count frequency
        for(char c : s)
            mp[c]++;

        int n = s.size();

        // Create buckets
        vector<vector<char>> bucket(n + 1);

        for(auto &p : mp)
        {
            bucket[p.second].push_back(p.first);
        }

        string ans = "";

        // Traverse from high frequency
        for(int i = n; i >= 1; i--)
        {
            for(char c : bucket[i])
            {
                ans += string(i, c);
            }
        }

        return ans;
    }
};