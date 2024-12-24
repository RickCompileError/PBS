// find the minimum number and make it as the minimum index
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int l = 0, r = sz - 1, m, idx;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                r = m; // not use m - 1 is due to nums[m] may be the minimum value
            } else {
                l = m + 1;
            }
        }

        r = l + sz - 1;
        while (l <= r) {
            m = l + (r - l) / 2;
            idx = m % sz;
            if (nums[idx] == target) {
                return idx;
            } else if (nums[idx] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
};

// only use the range in ascending order to check target is inside this range or not
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int l = 0, r = sz - 1, m;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
