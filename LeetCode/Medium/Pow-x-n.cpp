// Function Usage
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

// Exponential Operation, Time: O(nlogn), Space: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        double res = 1;
        long exp = abs((long)n); // boundary test, -2147483648

        while (exp) {
            if (exp & 1) {
                res *= x;
            }

            x *= x;
            exp >>= 1;
        }

        return n > 0 ? res : 1 / res;
    }
};
