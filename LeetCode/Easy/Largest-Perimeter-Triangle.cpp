// Time: O(nlogn), Space: O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int sz = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = sz - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }

        return 0;
    }
};
