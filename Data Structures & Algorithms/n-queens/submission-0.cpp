class Solution {
public:
    vector<bool> cols;
    vector<bool> rows;
    vector<bool> diagonal;
    vector<bool> anti;

    bool isSafe(int c, int r, int n) {
        if(cols[c]) return false;
        if(rows[r]) return false;
        if(diagonal[c + r]) return false;
        if(anti[c - r + n - 1]) return false; 

        return true;
    }

    void placeQueen(int c, vector<vector<string>>& ans, vector<string>& board, int n) {
        if(c == n) {
            ans.push_back(board);
            return;
        }

        for(int r = 0; r < n; r++) {
            if(isSafe(c, r, n)) {
                board[r][c] = 'Q';
                cols[c] = 1;
                rows[r] = 1;
                diagonal[c + r] = 1;
                anti[c - r + n - 1] = 1;
                
                placeQueen(c + 1, ans, board, n);

                board[r][c] = '.';
                cols[c] = 0;
                rows[r] = 0;
                diagonal[c + r] = 0;
                anti[c - r + n - 1] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n, string(n, '.')); 

        cols.assign(n, false);
        rows.assign(n, false);
        diagonal.assign(2 * n - 1, false);
        anti.assign(2 * n - 1, false);

        placeQueen(0, ans, board, n);

        return ans;
    }
};