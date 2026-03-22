class Solution {
public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            
            // Remove elements >= current
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // If stack empty → no smaller element
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());

            // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
};