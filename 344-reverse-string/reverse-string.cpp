class Solution {
public:
    void reverseString(vector<char>& arr) {

        stack<char> st;

        for(char c : arr){
            st.push(c);
        }

        int i = 0;
        while(!st.empty()){
            arr[i++] = st.top();
            st.pop();
        }
    }
};
