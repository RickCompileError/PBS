// Time: O(n), Space: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int accumulate = 0, sum = 0;
        for (int i = 1, sz = nums.size(); i < sz; i++) sum += nums[i];
        // pivot index = 0
        if (sum == 0) return 0;
        // pivot index between 1 ~ n-1
        for (int i = 1, sz = nums.size(); i < sz; i++) {
            accumulate += nums[i-1];
            sum -= nums[i];
            if (accumulate == sum) return i;
        }
        // no pivot index
        return -1;
    }
};