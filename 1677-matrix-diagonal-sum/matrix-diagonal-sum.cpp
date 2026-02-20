class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int first = 0;
        int sec = 0;

        int i = 0, j = 0;

        // primary diagonal
        while(i < row){
            first += mat[i][j];
            i++;
            j++;
        }

        // secondary diagonal
        i = 0;
        j = col - 1;

        while(i < row){
            sec += mat[i][j];
            i++;
            j--;
        }

        int total = first + sec;

        // subtract middle element if odd size
        if(row % 2 == 1){
            total -= mat[row/2][col/2];
        }

        return total;
    }
};
