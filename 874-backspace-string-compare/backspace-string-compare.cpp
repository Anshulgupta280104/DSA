class Solution {
public:
    string build(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != '#') {
                st.push(c);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        // Convert stack to string
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};