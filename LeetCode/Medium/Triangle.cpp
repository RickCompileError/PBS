// Time: O(mn), Space: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rsz = triangle.size();

        for (int r = 1; r < rsz; r++) {
            int csz = triangle[r].size();

            for (int c = 0; c < csz; c++) {
                triangle[r][c] = min(triangle[r][c] + (c - 1 >= 0 ? triangle[r - 1][c - 1] : 1e7), 
                    triangle[r][c] + (c < triangle[r - 1].size() ? triangle[r - 1][c] : 1e7));
            }
        }

        return *min_element(triangle[rsz - 1].begin(), triangle[rsz - 1].end());
    }
};
