// Time: O(m*n), Space: O(m*n)
#define IIDINT vector<vector<int>>
#define IIDBOOL vector<vector<bool>>

class Solution {
private:
    int ROWS;
    int COLS;
    int DIRY[4] = {0, 0, 1, -1};
    int DIRX[4] = {1, -1, 0, 0};

    void dfs(IIDINT& heights, IIDBOOL& touch, int r, int c) {
        touch[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int nxtR = r + DIRY[d];
            int nxtC = c + DIRX[d];
            if (nxtR < 0 || nxtR >= ROWS || nxtC < 0 || nxtC >= COLS) {
                continue;
            }
            if (touch[nxtR][nxtC] || heights[nxtR][nxtC] < heights[r][c]) {
                continue;
            }
            dfs(heights, touch, nxtR, nxtC);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        IIDBOOL pacific(ROWS, vector<bool>(COLS, false));
        IIDBOOL atlantic(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, COLS - 1);
        }
        for (int c = 0; c < COLS; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, ROWS - 1, c);
        }

        IIDINT result;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
