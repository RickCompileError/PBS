// Time: O(n^2), Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 1);
        
        for (int i = 1; i < sz; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// Time: O(nlogn), Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(1, nums[0])

        for (auto& i: nums) {
            if (dp.back() < i) {
                dp.push_back(i);
                ans++;
                continue;
            }

            int idx = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
            dp[idx] = i;
        }

        return ans;
    }
};
