class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        
        // Edge case handling
        if (k > n || k <= 0) return q;

        stack<int> st;

        // Step 1: Push first k elements into stack
        for(int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push back stack elements (reversed)
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move remaining (n-k) elements to back
        for(int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};