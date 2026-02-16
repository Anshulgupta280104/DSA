#include <unordered_set>
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        std::unordered_set<int> mySet;
        int n = arr.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            mySet.insert(arr[i]);
        }
        int count=0;
        int i=1;
        while(count<k){
            if(mySet.count(i)){
                i++;
            }
            else{
                v.push_back(i);
                count++;
                i++;
            }
        }
        return v[count-1];
    }
};