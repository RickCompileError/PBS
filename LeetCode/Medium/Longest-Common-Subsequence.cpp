// Time: O(mn), Space: O(mn)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size(), sz2 = text2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

        for (int i = sz1 - 1; i >= 0; i--) {
            for (int j = sz2 - 1; j >= 0; j--) {
                dp[i][j] = (text1[i] == text2[j] ?
                    1 + dp[i + 1][j + 1] :
                    max(dp[i + 1][j], dp[i][j + 1]));
            }
        }

        return dp[0][0];
    }
};

// Space optimized, Time: O(mn), Space: O(min(m, n))
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            swap(text1, text2);
        }

        vector<int> dp(text2.size() + 1, 0);

        for (int i = text1.size() - 1; i >= 0; i--) {
            int prev = 0;
            for (int j = text2.size() - 1; j >= 0; j--) {
                int tmp = dp[j];
                dp[j] = (text1[i] == text2[j] ? prev + 1 : max(dp[j], dp[j + 1]));
                prev = tmp;
            }
        }

        return dp[0];
    }
};
