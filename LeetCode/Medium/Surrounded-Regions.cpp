// Time: O(m*n), Space: O(m*n)
class Solution {
private:
    int ROWS;
    int COLS;
    pair<int,int> DIR[4]{{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == 'X' || visited[r][c]) {
            return;
        }
        visited[r][c] = true;

        for (auto& [y, x]: DIR) {
            dfs(board, visited, r + y, c + x);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        
        for (int i = 0; i < ROWS; i++) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, COLS - 1);
        }
        for (int i = 0; i < COLS; i++) {
            dfs(board, visited, 0, i);
            dfs(board, visited, ROWS - 1, i);
        }

        for (int r = 1; r < ROWS - 1; r++) {
            for (int c = 1; c < COLS - 1; c++) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
