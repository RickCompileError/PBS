// Time: O(n), Space: O(1)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = -1;
        double diagonalLen = -1;

        for (auto& dimension: dimensions) {
            double len = sqrt(dimension[0] * dimension[0] + dimension[1] * dimension[1]);
            if (diagonalLen <= len) {
                area = diagonalLen == len ? max(area, dimension[0] * dimension[1]) : dimension[0] * dimension[1];
                diagonalLen = len;
            }
        }

        return area;
    }
};
