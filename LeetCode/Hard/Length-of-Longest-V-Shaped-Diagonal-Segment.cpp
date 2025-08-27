// Time: O(mn), Space: O(mn), Timeout
class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rsz = grid.size(), csz = grid[0].size();
        // 0: top-left, 1: top-right 2: bottom-right, 3: bottom-left
        vector<vector<array<int,4>>> legalLengths(rsz, vector<array<int,4>>(csz));
        vector<vector<int>> moves{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

        for (int i = 0; i < rsz; i++) {
            for (int j = 0; j < csz; j++) {
                for (int m = 0; m < 4; m++) {
                    // count the length without element itself
                    int legalLen = 0;

                    int curR = i, curC = j;
                    int val = grid[i][j] == 1 ? 0 : grid[i][j];
                    curR += moves[m][0], curC += moves[m][1];

                    while (curR >= 0 && curR < rsz && curC >= 0 && curC < csz &&
                        grid[curR][curC] != val && grid[curR][curC] != 1) {
                        legalLen++;
                        val = grid[curR][curC];
                        curR += moves[m][0], curC += moves[m][1];
                    }

                    legalLengths[i][j][m] = legalLen;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < rsz; i++) {
            for (int j = 0; j < csz; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }

                for (int m = 0; m < 4; m++) {
                    int curR = i, curC = j;
                    int legalLen = 1;
                    int val = 0;
                    curR += moves[m][0], curC += moves[m][1];

                    // compare length without rotate
                    ans = max(ans, legalLen + legalLengths[i][j][m]);

                    while (curR >= 0 && curR < rsz && curC >= 0 && curC < csz &&
                        grid[curR][curC] != val && grid[curR][curC] != 1) {
                        legalLen++;

                        // compare length with rotate
                        ans = max(ans, legalLen + legalLengths[curR][curC][(m + 1) % 4]);
                        
                        val = grid[curR][curC];
                        curR += moves[m][0], curC += moves[m][1];
                    }
                }
            }
        }

        return ans;
    }
};
