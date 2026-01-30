class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> count(256, false);

        int first = 0, second = 0, len = 0;

        while (second < s.size()) {

            // remove duplicates
            while (count[s[second]]) {
                count[s[first]] = false;
                first++;
            }

            // add current char
            count[s[second]] = true;

            // update max length
            len = max(len, second - first + 1);

            second++;
        }

        return len;
    }
};
