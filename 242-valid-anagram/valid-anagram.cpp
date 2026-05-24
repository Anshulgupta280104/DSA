class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, not an anagram
        if(s.length() != t.length())
            return false;

        vector<int> freq(26, 0);

        // Count characters of s
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Remove characters using t
        for(char ch : t) {
            freq[ch - 'a']--;
        }

        // Check if all frequencies are 0
        for(int count : freq) {
            if(count != 0)
                return false;
        }

        return true;
    }
};