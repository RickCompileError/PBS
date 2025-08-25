// Time: O(N), Space: O(N)
class Solution {
private:
    int dp(vector<int>& v) {
        int r1{0}, r2{0}, t;
        
        for (int& i: v) {
            t = max(r1 + i, r2);
            r1 = r2;
            r2 = t;
        }

        return r2;
    }

public:
    int rob(vector<int>& nums) {
        vector v1(nums.begin(), nums.end() - 1);
        vector v2(nums.begin() + 1, nums.end());

        return max(nums[0], max(dp(v1), dp(v2)));
    }
};
