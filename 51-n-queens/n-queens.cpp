class Solution {
public:

    void solve(int row, int n,
               vector<string>& board,
               vector<vector<string>>& ans,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {

            // O(1) safety check
            if(col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;

            solve(row + 1, n, board, ans, col, diag1, diag2);

            // backtrack
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2*n, false);
        vector<bool> diag2(2*n, false);

        solve(0, n, board, ans, col, diag1, diag2);

        return ans;
    }
};
