class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int row=mat.size() , col=mat[0].size();
       for(int i=0;i<row-1;i++){
           for(int j=i+1;j<col;j++){
               swap(mat[i][j], mat[j][i]);
           }
       }
         return mat;
    }
};