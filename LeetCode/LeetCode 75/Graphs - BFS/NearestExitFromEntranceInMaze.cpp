// Time: O(m * n), Space: O(m + n)
class Solution {
public:

    int dirx[4] = {-1, 0, 0, 1};
    int diry[4] = {0, 1, -1, 0};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<array<int, 3>> q;

        // push starting point with initial step 0
        q.push({entrance[0], entrance[1], 0});

        // BFS
        while (!q.empty()) {
            auto [i, j, steps] = q.front(); q.pop();

            bool isEntrance = (i == entrance[0] && j == entrance[1]);
            bool isBorder = (i == 0 || i == m - 1 || j == 0 || j == n - 1);
            
            if (!isEntrance && isBorder) return steps;

            // Forward
            for (int d = 0; d < 4; d++) {
                int nextI = i + dirx[d];
                int nextJ = j + diry[d];
                if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && maze[nextI][nextJ] == '.') {
                    // mark the next cell to '+' so that we won't visit it again
                    maze[nextI][nextJ] = '+';
                    q.push({nextI, nextJ, steps + 1});
                }
            }
        }
        return -1;
    }
};