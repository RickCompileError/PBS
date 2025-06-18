// Time: O(nlogn), Space: O(n)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int sz = nums.size();
        int idx = 0;
        vector<vector<int>> v;

        sort(nums.begin(), nums.end());
        while (idx < sz) {
            if (nums[idx + 2] - nums[idx] <= k) {
                vector<int> sub;
                for (int i = 0; i < 3; i++) {
                    sub.push_back(nums[idx++]);
                }
                v.push_back(sub);
            } else {
                return {};
            }
        }

        return v;
    }
};
