class Solution {
public:
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    string sortVowels(string s) {
        string v;
        
        // Step 1: Collect vowels
        for(char c : s)
            if(isVowel(c)) v += c;

        // Step 2: Sort vowels
        sort(v.begin(), v.end());

        // Step 3: Replace using pointer
        int j = 0;
        for(int i = 0; i < s.size(); i++)
            if(isVowel(s[i]))
                s[i] = v[j++];

        return s;
    }
};