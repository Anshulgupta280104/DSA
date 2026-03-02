class Solution {
  public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
      
        
     for(int i=0;i<=n-1;i++)
     {
         if(arr[i]==x)
          return i;
          
    }
                 return -1;
    }

};