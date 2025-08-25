class Solution {
private:
    int row;
    int column;
    int getValue(auto& matrix, int pos) {
        return matrix[pos / column][pos % column];
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        row = matrix.size(), column = matrix[0].size();
        int sz = row * column;
        int l = 0, r = sz, m, v;

        while (l < r) {
            m = l + (r - l) / 2;
            v = getValue(matrix, m);
            if (v == target) {
                return true;
            }

            if (v > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
};
