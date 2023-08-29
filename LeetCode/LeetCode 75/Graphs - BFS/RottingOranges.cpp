// Time: O(m * n), Space: O(m + n)
class Solution {
public:

    int dirx[4] = {1, 0, 0, -1};
    int diry[4] = {0, 1, -1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0, mxMinutes = 0;
        queue<array<int, 3>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j, 0});
            }
        }
        while (!q.empty()) {
            auto [i, j, minutes] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nextI = i + dirx[d];
                int nextJ = j + diry[d];
                if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && grid[nextI][nextJ] == 1) {
                    fresh--;
                    grid[nextI][nextJ] = 2;
                    mxMinutes = max(mxMinutes, minutes + 1);
                    q.push({nextI, nextJ, minutes + 1});
                }
            }
        }

        return fresh == 0 ? mxMinutes : -1;
    }
};

// Clean code, remove mxMinutes
class Solution {
public:

    int dirx[4] = {1, 0, 0, -1};
    int diry[4] = {0, 1, -1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        int minutes = -1;
        int qSize;
        queue<array<int, 2>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        if (fresh == 0) return 0;
        
        while (!q.empty()) {
            qSize = q.size();
            while (qSize--) {
                auto [i, j] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nextI = i + dirx[d];
                    int nextJ = j + diry[d];
                    if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && grid[nextI][nextJ] == 1) {
                        fresh--;
                        grid[nextI][nextJ] = 2;
                        q.push({nextI, nextJ});
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};