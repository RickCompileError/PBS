// Time: O(1), Space: O(1)
// 1. power of 4 must greater than 0
// 2. check only one '1' bit
// 3. check the only one '1' bit is at the odd location
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && ((n & (n - 1)) == 0) && (n & 0x55555555) != 0;
    }
};
