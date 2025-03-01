// Time: O(n), Space: O(1)
class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size();
        int dpLen1 = 1, dpLen2 = 0, dp = 0;

        for (int i = sz - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp = 0;
            } else {
                dp = dpLen1;
                if (i + 1 < sz && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dp += dpLen2;
                }
            }
            
            dpLen2 = dpLen1;
            dpLen1 = dp;
            dp = 0;
        }

        return dpLen1;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size();
        vector<int> dp(sz + 1);
        dp[sz] = 1;

        for (int i = sz - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < sz && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};
