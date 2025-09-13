// Time: O(n), Space: O(1)
/* Proof:
 * condition: num1 = (2^i0 + 2^i1 + ...) + k * num2 = x + k * num2
 * x = num1 - k * num2
 * f(x) = number of 1 in x
 * f(x) <= k <= x
 */
class Solution {
private:
    int numberOfOne(long long x) {
        return x ? numberOfOne(x >> 1) + (x & 1) : 0;
    }

public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL * num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= numberOfOne(x)) {
                return k;
            }
        }
        return -1;
    }
};
