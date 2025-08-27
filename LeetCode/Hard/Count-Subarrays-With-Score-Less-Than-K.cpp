// Time: O(n), Space: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int sz = nums.size();
        int l = 0;

        for (int r = 0; r < sz; r++) {
            sum += nums[r];

            while (l <= r && sum * (r - l + 1) >= k) {
                sum -= nums[l++];
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
