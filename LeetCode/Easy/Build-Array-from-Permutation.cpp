// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans;
        for (int i = 0; i < sz; i++) {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
