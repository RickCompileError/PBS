// Time: O(logn), Space: O(logn)
class Solution {
private:
    int legalEven = 5, legalOdd = 4;
    const int MOD = 1e9 + 7;

    long long power(long long p, long long n) {
        if (n == 0) {
            return 1;
        }
        long long res = power(p, n / 2);
        return (n & 1 ? p * res * res : res * res) % MOD;
    }

public:
    int countGoodNumbers(long long n) {
        long long combEven = power(legalEven, (n + 1) / 2);
        long long combOdd = power(legalOdd, n / 2);
        return (combEven * combOdd) % MOD;
    }
};

// Time: O(logn), Space: O(1)
class Solution {
private:
    int legalEven = 5, legalOdd = 4;
    const int MOD = 1e9 + 7;

    long long power(long long p, long long n) {
        long long base = p;
        long long res = 1;

        while (n) {
            if (n & 1) {
                res *= base;
                res %= MOD;
            }
            base *= base;
            base %= MOD;
            n >>= 1;
        }

        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long combEven = power(legalEven, (n + 1) / 2);
        long long combOdd = power(legalOdd, n / 2);
        return (combEven * combOdd) % MOD;
    }
};
