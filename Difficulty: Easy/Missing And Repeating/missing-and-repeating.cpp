class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int N = arr.size();
        vector<int> count(N, 0);
        
        for(int i = 0; i < N; i++)
            count[arr[i] - 1]++;
        
        int missing = -1, repeating = -1;
        
        for(int i = 0; i < N; i++) {
            if(count[i] == 0)
                missing = i + 1;
            if(count[i] == 2)
                repeating = i + 1;
        }
        
        return {repeating, missing};
    }
};
