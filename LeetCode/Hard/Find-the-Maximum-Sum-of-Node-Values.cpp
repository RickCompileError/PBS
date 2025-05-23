// Time: O(n), Space: O(1)
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long xorResult = 0, sum = 0, cnt = 0, discard = INT_MAX;

        for (long long num: nums) {
            xorResult = num ^ k;
            sum += max(xorResult, num);
            cnt += (xorResult) > num;
            discard = min(discard, abs(num - (xorResult)));
        }

        return sum - (cnt % 2 ? discard : 0);
    }
};
