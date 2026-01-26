class Solution {
public:
    void reverseString(vector<char> &arr) {

        stack<char> st;

        // push all elements
        for(int i = 0; i < arr.size(); i++){
            st.push(arr[i]);
        }

        // pop back into array
        int i = 0;
        while(!st.empty()){
            arr[i] = st.top();
            st.pop();
            i++;
        }
    }
};
