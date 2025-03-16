// Time: O(m*n), Space: O(m*n)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();
        vector<vector<unsigned int>> dp(sz + 1, vector<unsigned int>(amount + 1, 0));

        dp[sz][amount] = 1;

        for (int i = sz - 1; i >= 0; i--) {
            int j = amount;
            while (j + coins[i] > amount && j >= 0) {
                dp[i][j] = dp[i + 1][j];
                j--;
            }

            while (j >= 0) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + coins[i]];
                j--;
            }
        }

        return dp[0][0];
    }
};

// Optimized, Time: O(m*n), Space: O(m)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();
        vector<unsigned int> dp(amount + 1, 0);

        dp[0] = 1;
        for (auto& coin: coins) {
            for (int i = 1; i <= amount; i++) {
                dp[i] = dp[i] + (i >= coin ? dp[i - coin] : 0);
            }
        }

        return dp[amount];
    }
};
