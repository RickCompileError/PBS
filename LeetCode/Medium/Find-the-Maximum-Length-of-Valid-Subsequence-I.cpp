// Time: O(n), Space: O(1)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int zeros = 0, ones = 0, flips = 0;
        bool flip = !(nums[0] & 1);

        for (auto& num: nums) {
            num &= 1;
            zeros += num == 0;
            ones += num == 1;
            flips += num ^ flip;
            if (num ^ flip) {
                flip = !flip;
            }
        }

        return max(zeros, max(ones, flips));
    }
};
