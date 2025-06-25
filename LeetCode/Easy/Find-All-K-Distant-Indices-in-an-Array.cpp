// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int sz = nums.size();
        vector<int> ans;

        for (int i = 0; i < sz; i++) {
            if (nums[i] != key) {
                continue;
            }
            int lastIdx = ans.empty() ? -1 : ans.back();
            for (int j = max(0, max(i - k, lastIdx + 1)); j < min(i + k + 1, sz); j++) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};
