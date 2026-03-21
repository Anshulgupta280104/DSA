class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {

        stack<int> st;

        for(int i = 0; i < arr.size(); i++) {

            if(st.empty()) {
                st.push(arr[i]);
            }
            else if((st.top() >= 0 && arr[i] < 0) || (st.top() < 0 && arr[i] >= 0)) {
                st.pop();
            }
            else {
                st.push(arr[i]);
            }
        }

        vector<int> result(st.size());

        int i = st.size() - 1;
        while(!st.empty()) {
            result[i--] = st.top();
            st.pop();
        }

        return result;
    }
};