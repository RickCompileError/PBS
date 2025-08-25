// Time: O(mn), Space: O(1)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0;
        int dir = 1;

        while (i < m && j < n) {
            ans.push_back(mat[i][j]);
            int nxtI = i + (dir ? -1 : 1);
            int nxtJ = j + (dir ? 1 : -1);

            if (nxtI < 0 || nxtI == m || nxtJ < 0 || nxtJ == n) {
                if (dir) {
                    i += (nxtJ == n ? 1 : 0);
                    j += (nxtJ == n ? 0 : 1);
                } else {
                    i += (nxtI == m ? 0 : 1);
                    j += (nxtI == m ? 1 : 0);
                }
                dir = 1 ^ dir;
            } else {
                i = nxtI;
                j = nxtJ;
            }
        }
        return ans;
    }
};
