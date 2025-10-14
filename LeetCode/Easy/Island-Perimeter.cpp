// Time: O(mn), Space: O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto f = [&](const auto &self, int r, int c) -> int {
            if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
                return 1;
            }

            if (grid[r][c] == -1) {
                return 0;
            }

            grid[r][c] = -1;
            return self(self, r - 1, c) + self(self, r + 1, c) + self(self, r, c - 1) + self(self, r, c + 1);
        };

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return f(f, i, j);
                }
            }
        }

        return 0;
    }
};
