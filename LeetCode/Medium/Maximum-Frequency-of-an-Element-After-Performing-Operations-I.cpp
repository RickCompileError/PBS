// Time: O(nlogn) or O(n) if not sort, Space: O(n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int mxVal = nums.back() + k + 2;
        vector<int> prefix(mxVal, 0);
        int sz = prefix.size();
        int ans = 0;

        for (auto& num: nums) {
            prefix[num]++;
        }
        for (int i = 1; i < sz; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < mxVal; i++) {
            int total = prefix[min(mxVal - 1, i + k)] - prefix[max(0, i - k - 1)];
            int freq = prefix[i] - (i ? prefix[i - 1] : 0);
            ans = max(ans, freq + min(numOperations, total - freq));
        }

        return ans;
    }
};
