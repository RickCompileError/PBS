// Time: O(1), Space: O(1)
// log(n) / log(3) = log3(n)
// if n is power of n, log3(n) must be integer
class Solution {
public:
    bool isPowerOfThree(int n) {
        double p = log10(n) / log10(3);
        return n > 0 && p - (int)p == 0;
    }
};
