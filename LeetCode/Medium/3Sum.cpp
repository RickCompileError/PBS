class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int twoSum = -nums[i];
            int l = i + 1, r = sz - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum > twoSum) {
                    r--;
                } else if (sum < twoSum) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};
