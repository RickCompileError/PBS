// Time: O(logn), Space: O(1)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while (a > 0 || b > 0 || c > 0) {
            flips += (c & 1 ? (((a | b) & 1) == 0) : ((a & 1) + (b & 1)));
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};
