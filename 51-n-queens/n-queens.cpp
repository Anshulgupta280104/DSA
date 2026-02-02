class Solution {
public:

    // check diagonals
    bool check(int n, vector<string>& Board, int i, int j) {

        int row = i, col = j;

        // upper-left diagonal
        while(row >= 0 && col >= 0) {
            if(Board[row][col] == 'Q')
                return false;
            row--; col--;
        }

        // upper-right diagonal
        row = i; col = j;
        while(row >= 0 && col < n) {
            if(Board[row][col] == 'Q')
                return false;
            row--; col++;
        }

        return true;
    }


    void find(int row, int n,
              vector<vector<string>>& ans,
              vector<string>& Board,
              vector<bool>& column) {

        if(row == n) {
            ans.push_back(Board);
            return;
        }

        for(int j = 0; j < n; j++) {

            if(!column[j] && check(n, Board, row, j)) {

                column[j] = true;
                Board[row][j] = 'Q';

                find(row + 1, n, ans, Board, column);

                column[j] = false;   // backtrack
                Board[row][j] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> Board(n, string(n, '.'));

        vector<bool> column(n, false);

        find(0, n, ans, Board, column);

        return ans;
    }
};
