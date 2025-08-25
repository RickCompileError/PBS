// 2D-DP, Time: O(m*n), Space: O(m*n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();

        if (sz1 + sz2 != sz3) {
            return false;
        }

        vector<vector<bool>> dp(sz1 + 1, vector<bool>(sz2 + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= sz1; i++) {
            for (int j = 0; j <= sz2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                    dp[i][j] = true;
                }

                if (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[sz1][sz2];
    }
};

// 1D-DP, Time: O(m*n), Space: O(min(m,n))
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() > s2.size()) {
            swap(s1, s2);
        }

        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();

        if (sz1 + sz2 != sz3) {
            return false;
        }

        vector<bool> dp(sz2 + 1, false);
        dp[sz2] = true;

        for (int i = 0; i <= sz1; i++) {
            int s2Dp = true;
            for (int j = 1; j <= sz2; j++) {
                int res = false;

                if (i > 0 && s1[i - 1] == s3[i + j - 1] && dp[j]) {
                    res = true;
                }

                if (j > 0 && s2[j - 1] == s3[i + j - 1] && s2Dp) {
                    res = true;
                }

                dp[j] = res;
                s2Dp = dp[j];
            }
        }

        return dp[sz2];
    }
};
