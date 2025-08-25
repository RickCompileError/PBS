// Time: O(m*n), Space: O(m*n)
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        return 1 +
            dfs(grid, r + 1, c) +
            dfs(grid, r - 1, c) +
            dfs(grid, r, c + 1) +
            dfs(grid, r, c - 1);
    }
public:
    int ROWS;
    int COLS;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mxArea = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                mxArea = max(mxArea, dfs(grid, i, j));
            }
        }

        return mxArea;
    }
};
