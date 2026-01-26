class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        vector<int> arr;

        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }

        st.push(x);

        // 🔥 reverse push (fix)
        for(int i = arr.size()-1; i >= 0; i--){
            st.push(arr[i]);
        }

        return st;
    }
};
