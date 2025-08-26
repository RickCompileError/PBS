// Time: O(n), Space: O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();

        for (int i = 1; i < sz - 1; i++) {
            if (nums[i] & 1) {
                continue;
            }
            if (nums[i - 1] + nums[i + 1] == (nums[i] >> 1)) {
                ans++;
            }
        }

        return ans;
    }
};
