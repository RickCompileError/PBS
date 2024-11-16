class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int counter = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (i == 0 || nums[i - 1] + 1 == nums[i]) {
                counter++;
            } else {
                counter = 1;
            }

            if (i + 1 < k) continue;

            ans.push_back(counter < k ? -1 : nums[i]);
        }

        return ans;
    }
};
