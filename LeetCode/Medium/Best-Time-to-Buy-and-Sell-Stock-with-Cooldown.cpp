// Recursion, Time: O(2^n), Space: O(n)
class Solution {
private:
    int dfs(int idx, bool buy, vector<int>& prices) {
        if (idx >= prices.size()) {
            return 0;
        }

        int cooldown = dfs(idx + 1, buy, prices);

        if (buy) {
            int buy = dfs(idx + 1, false, prices) - prices[idx];
            return max(cooldown, buy);
        } else {
            int sell = dfs(idx + 2, true, prices) + prices[idx];
            return max(cooldown, sell);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }
};

// Bottom-Up, Time: O(n), Space: O(n)
#define buy first
#define sell second

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<pair<int,int>> dp(sz + 2, {0, 0});

        for (int i = sz - 1; i >= 0; i--) {
            dp[i].buy = max(dp[i + 1].buy, dp[i + 1].sell - prices[i]);
            dp[i].sell = max(dp[i + 1].sell, dp[i + 2].buy + prices[i]);
        }

        return dp[0].buy;
    }
};

// Space Optimzied, Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int tomorrowBuy = 0, tomorrowSell = 0;
        int afterTwoBuy = 0;

        for (int i = sz - 1; i >= 0; i--) {
            int todayBuy = max(tomorrowBuy, tomorrowSell - prices[i]);
            int todaySell = max(tomorrowSell, afterTwoBuy + prices[i]);
            afterTwoBuy = tomorrowBuy;
            tomorrowBuy = todayBuy;
            tomorrowSell = todaySell;
        }

        return tomorrowBuy;
    }
};
