// O(m * 4^n), Space: O(m), m is the board size, n is the word size
class Solution {
private:
    int m;
    int n;
    bool legal;
    int dirY[4] = {1, -1, 0, 0};
    int dirX[4] = {0, 0, 1, -1};

    void backtracking(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int idx, int y, int x) {
        if (idx == word.size()) {
            legal = true;
            return;
        }

        int nxtY, nxtX;
        for (int i = 0; i < 4; i++) {
            nxtY = y + dirY[i];
            nxtX = x + dirX[i];
            if (nxtY < 0 || nxtY >=m || nxtX < 0 || nxtX >= n ||
                visited[nxtY][nxtX] || word[idx] != board[nxtY][nxtX]) {
                continue;
            }

            visited[y][x] = true;
            backtracking(board, visited, word, idx + 1, nxtY, nxtX);
            visited[y][x] = false;
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        legal = false;
        for (int i = 0; i < m && !legal; i++) {
            for (int j = 0; j < n && !legal; j++) {
                if (word[0] != board[i][j]) {
                    continue;
                }
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                backtracking(board, visited, word, 1, i, j);
            }
        }
        return legal;
    }
};

// To make the optimization, we can replace the board if the position was visited to save the space
// after backtracking, we can use word[idx] to recover the board
