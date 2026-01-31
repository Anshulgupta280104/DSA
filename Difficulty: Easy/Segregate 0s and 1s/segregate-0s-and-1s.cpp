class Solution {
public:
    void segregate0and1(vector<int> &arr) {

        int n = arr.size();

        int count0 = 0, count1 = 0;

        // count 0s and 1s
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0)
                count0++;
            else
                count1++;
        }

        // fill 0s
        for(int i = 0; i < count0; i++)
            arr[i] = 0;

        // fill 1s
        for(int i = count0; i < n; i++)
            arr[i] = 1;
    }
};
