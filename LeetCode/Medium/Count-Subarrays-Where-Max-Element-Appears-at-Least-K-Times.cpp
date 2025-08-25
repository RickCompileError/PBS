// Time: O(n), Space: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mxNum = *max_element(nums.begin(), nums.end());
        int sz = nums.size();
        long long ans = 0;
        queue<int> q;

        for (int i = 0; i < sz; i++) {
            if (nums[i] == mxNum) {
                q.push(i);
            }
            if (q.size() > k) {
                q.pop();
            }
            if (q.size() == k) {
                ans += q.front() + 1;
            }
        }

        return ans;
    }
};
