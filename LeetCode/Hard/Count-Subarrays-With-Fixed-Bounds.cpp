// Time: O(n), Space: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int rMostBad = -1, rMostMn = -1, rMostMx = -1, sz = nums.size();
        long long res = 0;

        for (int i = 0; i < sz; i++) {
            if (nums[i] < minK || nums[i] > maxK) rMostBad = i;
            if (nums[i] == minK) rMostMn = i;
            if (nums[i] == maxK) rMostMx = i;
            res += max(0, min(rMostMn, rMostMx) - rMostBad);
        }

        return res;
    }
};
