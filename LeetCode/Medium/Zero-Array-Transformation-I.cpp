// Time: O(n), Space: O(n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sz = nums.size();
        vector<int> prefix(sz + 1, 0);

        for (auto& query: queries) {
            prefix[query[0]]++;
            prefix[query[1] + 1]--;
        }
        for (int i = 1; i <= sz; i++) {
            prefix[i] += prefix[i - 1];
        }
        for (int i = 0; i < sz; i++) {
            if (nums[i] > 0 && nums[i] > prefix[i]) {
                return false;
            }
        }

        return true;
    }
};
