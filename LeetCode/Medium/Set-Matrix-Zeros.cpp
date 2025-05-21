// Time: O(m*n), Space: O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        unordered_set<int> r0, c0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!matrix[i][j]) {
                    r0.insert(i);
                    c0.insert(j);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (r0.count(i) || c0.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// There is an optimize version is only set 0 on col and row [0] first
// Time: O(mn), Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        bool rZero = false, cZero = false;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (r == 0 && matrix[r][c] == 0) {
                    rZero = true;
                }
                if (c == 0 && matrix[r][c] == 0) {
                    cZero = true;
                }
                if (r > 0 && c > 0 && matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        for (int r = 1; r < ROW; r++) {
            for (int c = 1; c < COL; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (rZero) {
            for (int c = 0; c < COL; c++) {
                matrix[0][c] = 0;
            }
        }
        if (cZero) {
            for (int r = 0; r < ROW; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};
