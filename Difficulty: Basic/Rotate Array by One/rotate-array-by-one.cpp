class Solution {
public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: store last element
        int last = arr[n - 1];
        
        // Step 2: shift elements right
        for(int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        
        // Step 3: put last element at front
        arr[0] = last;
    }
};
