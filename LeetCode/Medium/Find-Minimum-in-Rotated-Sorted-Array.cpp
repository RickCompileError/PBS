class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int l = 0, r = sz - 1, m;

        if (nums[l] <= nums[r]) {
            return nums[l];
        }

        while (l + 1 < r) {
            m = l + (r - l) / 2;
            if (nums[m] > nums[l]) {
                l = m;
            } else {
                r = m;
            }
        }

        return nums[r];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int l = 0, r = sz - 1, m;

        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] <= nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return nums[l]
    }
};
