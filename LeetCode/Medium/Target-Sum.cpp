// Backtracking, Time: O(2^n), Space: O(n)
class Solution {
private:
    int result = 0;

    void backtracking(vector<int>& nums, vector<int>& acc, int idx, int cur, int& target) {
        if (idx == nums.size()) {
            if (cur == target) {
                result++;
            }
            return;
        }

        if (abs(cur - target) > acc[idx]) {
            return;
        }

        backtracking(nums, acc, idx + 1, cur + nums[idx], target);
        backtracking(nums, acc, idx + 1, cur - nums[idx], target);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> acc(sz + 1, 0);

        for (int i = sz - 1; i >= 0; i--) {
            acc[i] = acc[i + 1] + nums[i];
        }
        backtracking(nums, acc, 0, 0, target);

        return result;
    }
};

// DP, Time: O(n*m), Space: O(m), n = size of nums, m = # of elements in map
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> dp;
        dp[0] = 1;

        for (auto& num: nums) {
            unordered_map<int,int> nxtDp;

            for (auto& [k, v]: dp) {
                nxtDp[k + num] += v;
                nxtDp[k - num] += v;
            }

            dp = nxtDp;
        }

        return dp[target];
    }
};
