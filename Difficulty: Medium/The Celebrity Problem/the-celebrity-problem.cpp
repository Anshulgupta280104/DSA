class Solution {
public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st;

        // Step 1: push all
        for(int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: elimination
        while(st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if(M[a][b] == 1)
                st.push(b);
            else
                st.push(a);
        }

        // Step 3: verify
        int candidate = st.top();

        for(int i = 0; i < n; i++) {
            if(i != candidate) {
                if(M[candidate][i] == 1 || M[i][candidate] == 0)
                    return -1;
            }
        }

        return candidate;
    }
};