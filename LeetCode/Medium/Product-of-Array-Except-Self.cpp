class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        int cml = 1;
        vector<int> ans(nums.size(), 1);

        // prefix product of cumulative
        for (int i = 1; i < sz; i++) {
            cml *= nums[i - 1];
            ans[i] *= cml;
        }

        cml = 1;

        // postfix product of cumulative
        for (int i = sz - 2; i >= 0; i--) {
            cml *= nums[i + 1];
            ans[i] *= cml;
        }

        return ans;
    }
};
