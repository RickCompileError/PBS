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
