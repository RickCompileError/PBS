// DP, Time: O(m*n), Space: O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};

// DP, Optimized
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n];
	}
};

// Math, Time: O(min(m, n)), Space: O(1)
#define ll long long

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        if (m > n) {
            swap(m, n);
        }

        ll ans = 1;
        int pathLen = m + n - 2;
        for (int i = n, j = 1; i <= pathLen; i++, j++) {
            ans *= i;
            ans /= j;
        }

        return ans;
    }
};
