// Time: O(nlogn), Space: O(n)
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        int sz = nums.size();
        int count = 0;
        int l = 0, r = sz - 1;
        vector<int> pows(sz, 1);

        sort(nums.begin(), nums.end());
        for (int i = 1; i < sz; i++) {
            pows[i] = pows[i - 1] * 2 % MOD;
        }
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                count = (count + pows[r - l++]) % MOD;
            }
        }

        return count;
    }
};
