// Time: O(n^2), Space: O(nk)
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int sz = nums.size();
        int ans = 0;
        vector<vector<int>> dp(sz, vector<int>(k, 0));

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                int m = (nums[i] + nums[j]) % k;
                dp[i][m] = max(dp[i][m], dp[j][m] + 1);
                ans = max(ans, dp[i][m]);
            }
        }

        return ans + 1;
    }
};
