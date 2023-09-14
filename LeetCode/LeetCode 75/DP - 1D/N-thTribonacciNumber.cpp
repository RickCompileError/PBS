// Time: O(n), Space: O(1)
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int t0 = 0, t1 = 0, t2 = 1, t3 = 1;
        for (int i = 3; i <= n; i++) {
            t0 = t1;
            t1 = t2;
            t2 = t3;
            t3 = t0 + t1 + t2;
        }
        return t3;
    }
};

// another version, more precise
class Solution {
public:
    int tribonacci(int n) {
        int dp[]{0, 1, 1};
        for (int num = 3; num <= n; num++) {
            dp[num % 3] = dp[0] + dp[1] + dp[2];
        }
        return dp[n % 3];
    }
};