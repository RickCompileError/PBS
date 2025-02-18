// Time: O(N), Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        int mx = 0;

        for (int i = 1; i < sz; i++) {
            nums[i] += mx;
            mx = max(mx, nums[i - 1]);
        }

        return max(mx, nums[sz - 1]);
    }
};
