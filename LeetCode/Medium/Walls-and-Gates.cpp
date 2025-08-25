// Time: O(m*n), Space: O(m*n)
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int DIRY[4] = {1, -1, 0, 0};
        int DIRX[4] = {0, 0, 1, -1};

        queue<array<int,2>> cells;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0) {
                    cells.push({r, c});
                }
            }
        }

        while (!cells.empty()) {
            int r = cells.front()[0];
            int c = cells.front()[1];
            cells.pop();
            for (int d = 0; d < 4; d++) {
                int nxtR = r + DIRY[d];
                int nxtC = c + DIRX[d];

                if (nxtR < 0 || nxtR >= ROWS || nxtC < 0 || nxtC >= COLS || grid[nxtR][nxtC] < INT_MAX) {
                    continue;
                }

                grid[nxtR][nxtC] = grid[r][c] + 1;
                cells.push({nxtR, nxtC});
            }
        }
    }
};

