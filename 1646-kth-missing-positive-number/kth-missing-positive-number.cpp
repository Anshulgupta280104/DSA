class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int missing = 0;

        for(int i=0; i<arr.size(); i++){
            
            missing = arr[i] - (i+1);

            if(missing >= k)
                return k + i;
        }

        return k + arr.size();
    }
};
