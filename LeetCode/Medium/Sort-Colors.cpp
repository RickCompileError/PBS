// Time: O(n), Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size(), left = 0, mid = 0, right = sz - 1;

        for (; mid <= right;) {
            if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};
