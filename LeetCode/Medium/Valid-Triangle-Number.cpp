// Binary Search
// Time: O(nlogn + n^2logn), Space: O(1)
// a + b > c
// a - b < c
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            for (int j = sz - 1; j > i; j--) {
                int range = (int)(nums.begin() + j - lower_bound(nums.begin() + i + 1, nums.begin() + j, nums[j] - nums[i] + 1));
                ans += range;
            }
        }

        return ans;
    }
};

// Three Sum
// Time: O(n^2), Space: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int sz = nums.size();

        for (int k = sz - 1; k > 1; k--) {
            for (int i = 0, j = k - 1; i < j;) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};
