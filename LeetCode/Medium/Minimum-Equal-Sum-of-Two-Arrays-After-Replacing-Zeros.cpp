// Time: O(m+n), Space: O(1)
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        bool hasZero1 = false, hasZero2 = false;

        for (auto& num: nums1) {
            hasZero1 |= num == 0;
            sum1 += num ? num : hasZero1;
        }
        for (auto& num: nums2) {
            hasZero2 |= num == 0;
            sum2 += num ? num : hasZero2;
        }
        if (sum1 > sum2) {
            return hasZero2 ? sum1 : -1;
        }
        if (sum1 < sum2) {
            return hasZero1 ? sum2 : -1;
        }
        return sum1;
    }
};
