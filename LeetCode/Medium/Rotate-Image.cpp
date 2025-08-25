// Time: O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size();

        for (auto& i: matrix) {
            reverse(i.begin(), i.end());
        }
        
        for (int i = 0; i < sz; i++) {
            for (int j = sz - i - 1; j >= 0; j--) {
                swap(matrix[i][j], matrix[sz - j - 1][sz - i - 1]);
            }
        }
    }
};
