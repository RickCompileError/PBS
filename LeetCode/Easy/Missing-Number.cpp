// Bit way
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

// Math way
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size();
        for (auto i: nums) sum += i;
        return sz * (sz + 1) / 2 - sum;
    }
};
