// Backtracking, Time Exceeded, Time: O(2^n), Space: O(2^n)
class Solution {
private:
    bool backtracking(vector<int>& nums, int sum, int idx, int half) {
        if (sum == half) {
            return true;
        }

        if (idx == nums.size() || sum < half) {
            return false;
        }

        return backtracking(nums, sum - nums[idx], idx + 1, half) ||
            backtracking(nums, sum, idx + 1, half);
    }

public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);

        return s & 1 ? false : backtracking(nums, s, 0, s / 2);
    }
};

// DP, Time: O(n * target), Space: O(target), n = the amount of nums, target = half of sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        int half = sum / 2;
        int idx = nums.size();
        vector<bool> dp(half + 1, false);
        dp[0] = true;

        for (int& num: nums) {
            for (int i = half; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[half];
    }
};

// Space Optimized, Time: O(n * target), Space: O(target)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        int half = sum / 2;
        bitset<10001> dp;
        dp[0] = true;

        for (int& num: nums) {
            dp |= dp << num;
        }

        return dp[half];
    }
};
