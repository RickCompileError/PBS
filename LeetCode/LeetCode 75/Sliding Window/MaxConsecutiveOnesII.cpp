// Time: O(n), Memory: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = INT_MIN, left = 0, flip = 0;
        for (int i = 0, sz = nums.size(); i < sz; i++) {
            if (nums[i] == 0) {
                if (flip < k) flip++;
                else {
                    // find next zero should be discard
                    while (nums[left] == 1) left++;
                    // skip to next whatever it is 0 or 1
                    left++;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

/* 
 * Another version, more concise, not really intuitive
 * for each nums[j], try to find the largest subarray
 * if nums[i] ~ nums[j] has zero <= k, increment j
 * if nums[i] ~ nums[j] has zero > k, increment both i and j
 */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, sz = nums.size();
        for (; j < sz; j++) {
            if (nums[j] == 0) k--;
            if (k < 0 && nums[i++] == 0) k++;
        }
        return j - i;
    }
};