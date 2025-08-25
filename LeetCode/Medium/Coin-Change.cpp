// Time: O(n*m), Space: O(n)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= amount; i++) {
            for (auto& coin: coins) {
                if (i - coin < 0 || dp[i - coin] == 0) {
                    continue;
                }
                dp[i] = dp[i] == 0 ? dp[i - coin] + 1 : min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] - 1;
    }
};

// reverse, avoid overflow case
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[amount] = 1;

        for (int i = amount; i >= 0; i--) {
            if (dp[i] == 0) {
                continue;
            }

            for (auto& coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i - coin] = dp[i - coin] == 0 ? dp[i] + 1 : min(dp[i] + 1, dp[i - coin]);
            }
        }

        return dp[0] - 1;
    }
};

// Another Logic
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[amount] = 0;

        for (int i = amount; i >= 0; i--) {
            for (auto& coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i - coin] = min(dp[i - coin], dp[i] + 1);
            }
        }

        return dp[0] == amount + 1 ? -1 : dp[0];
    }
};
