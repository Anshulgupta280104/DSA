class Solution {
public:
    vector<int> help_classmate(vector<int> arr, int n) {
        vector<int> ans(n, -1);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};