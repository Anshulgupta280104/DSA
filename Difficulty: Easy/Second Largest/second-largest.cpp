class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
       int n = arr.size();
       
       int maxval = arr[0];
       
       // Find largest
       for(int i = 1; i < n; i++){
           if(arr[i] > maxval)
               maxval = arr[i];
       }
       
       int Secondmaxval = -1;  // initialize properly
       
       // Find second largest
       for(int i = 0; i < n; i++){
           if(arr[i] > Secondmaxval && arr[i] < maxval)
               Secondmaxval = arr[i];
       }
       
       return Secondmaxval;
    }
};
