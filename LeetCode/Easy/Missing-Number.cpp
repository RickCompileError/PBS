class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        for (int i = 1; i <= sz; i++) {
            ans ^= i;
        }
        for (auto i: nums) {
            ans ^= i;
        }
        return ans;
    }
};
