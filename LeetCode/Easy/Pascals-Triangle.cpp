// Time: O(n^2), Space: O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());

        ans[0].push_back(1);
        for (int i = 2; i <= numRows; i++) {
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    ans[i - 1].push_back(1);
                } else {
                    ans[i - 1].push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
                }
            }
        }

        return ans;
    }
};
