// Time: O(n), Space: O(1)
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int sz = nums.size();
        int mx = -1;

        for (int i = 1; i < sz; i++) {
            mx = max(mx, abs(nums[i] - nums[i - 1]));
        }

        return max(mx, abs(nums[0] - nums[sz - 1]));
    }
};
