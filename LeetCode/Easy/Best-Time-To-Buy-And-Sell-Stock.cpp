class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mn = prices[0];

        for (auto& i: prices) {
            mn = min(mn, i);
            ans = max(ans, i - mn);
        }

        return ans;
    }
};
