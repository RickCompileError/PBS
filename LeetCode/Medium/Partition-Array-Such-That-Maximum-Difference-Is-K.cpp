// Time: O(nlogn), Space: O(1)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int seq = 1;

        sort(nums.begin(), nums.end());
        int mn = nums[0];
        for (auto& num: nums) {
            if (num - mn > k) {
                mn = num;
                seq++;
            }
        }

        return seq;
    }
};
