// Time: O(n), Space: O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int sz = nums.size();
        int mn = nums[0];
        int mx = INT_MIN;

        for (int i = 1; i < sz; i++) {
            if (nums[i] > mn) {
                mx = max(mx, nums[i] - mn);
            }
            mn = min(mn, nums[i]);
        }

        return mx == INT_MIN ? -1 : mx;
    }
};
