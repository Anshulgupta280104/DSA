class Solution {
public:
    string reverseWords(string s) {

        // Step 1: reverse whole string
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;
        int l = 0, r = 0;

        while(i < n){

            // skip spaces
            while(i < n && s[i] == ' ')
                i++;

            if(i == n) break;

            // mark start of word
            while(i < n && s[i] != ' ')
                s[r++] = s[i++];

            // reverse the word
            reverse(s.begin() + l, s.begin() + r);

            s[r++] = ' ';
            l = r;
        }

        // remove last space
        s.resize(r - 1);

        return s;
    }
};