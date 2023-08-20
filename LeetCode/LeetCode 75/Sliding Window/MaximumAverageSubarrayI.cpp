// Time: O(n), Memory: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans, tmp = 0;
        for (int i = 0; i < k; i++) tmp += nums[i];
        ans = tmp / k;
        for (int i = k, sz = nums.size(); i < sz; i++) {
            tmp = tmp + nums[i] - nums[i-k];
            ans = max(ans, tmp / k);
        }
        return ans;
    }
};