class Solution {
private:
    pair<int,int> DIR[4]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int d = 0;
        int m = matrix.size(), n = matrix[0].size();
        int rowTop = 0, rowBottom = m - 1, colLeft = 0, colRight = n - 1;
        vector<int> spiral;

        while ((d % 2 == 0 && colLeft <= colRight) || (d % 2 == 1 && rowTop <= rowBottom)) {
            switch (d) {
            case 0:
                for (int i = colLeft; i <= colRight; i++) {
                    spiral.push_back(matrix[rowTop][i]);
                }
                rowTop++;
                break;
            case 1:
                for (int i = rowTop; i <= rowBottom; i++) {
                    spiral.push_back(matrix[i][colRight]);
                }
                colRight--;
                break;
            case 2:
                for (int i = colRight; i >= colLeft; i--) {
                    spiral.push_back(matrix[rowBottom][i]);
                }
                rowBottom--;
                break;
            case 3:
                for (int i = rowBottom; i >= rowTop; i--) {
                    spiral.push_back(matrix[i][colLeft]);
                }
                colLeft++;
                break;
            default:
                break;
            }

            d = (d + 1) % 4;
        }

        return spiral;
    }
};

// Optimal
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0},
                                             {0, -1}, {-1, 0}};
        vector<int> steps = {matrix[0].size(), matrix.size() - 1};

        int r = 0, c = -1, d = 0;
        while (steps[d % 2]) {
            for (int i = 0; i < steps[d % 2]; i++) {
                r += directions[d].first;
                c += directions[d].second;
                res.push_back(matrix[r][c]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return res;
    }
};
