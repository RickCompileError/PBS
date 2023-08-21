// Complexity: O(n), Space: O(1) (12ms)
// Note: the space complexity is O(1) if output array doesn't count as extra space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cumulative = 1, sz = nums.size();
        vector<int> ans(sz, 1);
        for (int i = 1; i < sz; i++) cumulative *= nums[i-1], ans[i] = cumulative;
        cumulative = 1;
        for (int i = sz - 2; i >= 0; i--) cumulative *= nums[i+1], ans[i] *= cumulative;
        return ans;
    }
};

// more concise but more runtime (22ms)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cumulative = 1, sz = nums.size();
        vector<int> ans(sz, 1);
        for (int i = 1; i < sz; i++) ans[i] = ans[i-1] * nums[i-1];
        for (int i = sz - 2; i >= 0; i--) cumulative *= nums[i+1], ans[i] *= cumulative;
        return ans;
    }
};