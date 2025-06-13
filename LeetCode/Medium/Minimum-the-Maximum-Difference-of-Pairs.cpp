// Time: O(nlog(max(A)) + nlogn), Space: O(1)
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[sz - 1] - nums[0];

        while (left < right) {
            int mid = (left + right) / 2, k = 0;

            for (int i = 1; i < sz && k < p; ++i) {
                if (nums[i] - nums[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }

            if (k >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
