// O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, z = 0, sz = nums.size(), ans = 0;

        while (r < sz) {
            if (!nums[r]) z++;
            while (z > k) {
                if (!nums[l]) z--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
