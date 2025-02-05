// Time: O(m*n), Space: O(m*n)
class Solution {
private:
    int ROWS;
    int COLS;
    int dirY[4] = {1, -1, 0, 0};
    int dirX[4] = {0, 0, 1, -1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int rottingTime = 0;

        queue<vector<int>> rotCells;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] != 2) {
                    continue;
                }
                rotCells.push({i, j, 0});
            }
        }

        while (!rotCells.empty()) {
            vector<int> rotCell = rotCells.front();
            rotCells.pop();

            if (grid[rotCell[0]][rotCell[1]] == 1) {
                rottingTime = max(rottingTime, rotCell[2]);
            }
            grid[rotCell[0]][rotCell[1]] = 0;

            for (int d = 0; d < 4; d++) {
                int r = rotCell[0] + dirY[d];
                int c = rotCell[1] + dirX[d];

                if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != 1) {
                    continue;
                }
                rotCells.push({r, c, rotCell[2] + (grid[r][c] == 1)});
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return rottingTime;
    }
};

// Simplify
class Solution {
private:
    int ROWS;
    int COLS;
    int dirY[4] = {1, -1, 0, 0};
    int dirX[4] = {0, 0, 1, -1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int rottingTime = -1;
        int freshOrange = 0;
        queue<array<int,2>> rotCells;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) freshOrange++;
                if (grid[r][c] == 2) rotCells.push({r, c});
            }
        }

        if (freshOrange == 0) {
            return 0;
        }

        while (!rotCells.empty()) {
            int rottedAmount = rotCells.size();
            rottingTime++;

            while (rottedAmount--) {
                auto [r, c] = rotCells.front();
                rotCells.pop();
                for (int d = 0; d < 4; d++) {
                    int nxtR = r + dirY[d];
                    int nxtC = c + dirX[d];

                    if (nxtR >= 0 && nxtR < ROWS && nxtC >= 0 && nxtC < COLS && grid[nxtR][nxtC] == 1) {
                        freshOrange--;
                        grid[nxtR][nxtC] = 2;
                        rotCells.push({nxtR, nxtC});
                    }
                }
            }
        }

        return freshOrange ? -1 : rottingTime;
    }
};
