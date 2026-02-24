class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int N= mat.size();
        int M= mat[0].size();
     int i=0, j=M-1;
     while(i<N && j>=0)
     {
         if(mat[i][j]==x)
         return 1;
         
         else if(mat[i][j]< x)
         i++;
         else
         j--;
     }
        return 0;
    }
};