// DP, Time: O(n), Space: O(n)
class Solution {
public:
    long long countPowerful(long long finish, int limit, string s) {
        string f = to_string(finish);
        int prefixLength = f.size() - s.size();
        if (prefixLength < 0) {
            return 0;
        }

        // dp[i][mode]: mode = 0 (free), 1 (strict)
        vector<vector<long long>> dp(prefixLength + 1, vector<long long>(2, 0));
        // base: value in same length => ex. "12345" and "300", compare "345" and "300"
        dp[prefixLength][0] = 1;
        dp[prefixLength][1] = f.substr(prefixLength) >= s ? 1 : 0;

        for (int i = prefixLength - 1; i >= 0; i--) {
            int curDigit = f[i] - '0';

            // no restriction: from 0 to limit
            dp[i][0] = (limit + 1) * dp[i + 1][0];

            // strict case: digits <= current digit
            if (curDigit <= limit) {
                // (from 0 to curDigit - 1) * legal amount of DP + curDigit: legal amount of DP
                // ex. "334" "4" "4"
                // (0 ~ 2) * dp[i + 1][0] + (3)dp[i + 1][1]
                dp[i][1] = (long long) curDigit * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (long long) (limit + 1) * dp[i + 1][0];
            }
        }

        return dp[0][1];
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countPowerful(finish, limit, s) - countPowerful(start - 1, limit, s);
    }
};

// Combination, Time: O(n), Space: O(n)
class Solution {
public:
    long long countPowerful(string f, int limit, string s) {
        if (f.size() < s.size()) {
            return 0;
        }

        if (f.size() == s.size()) {
            return f >= s;
        }

        int preLen = f.size() - s.size();
        string suffix = f.substr(preLen);
        long long count = 0;

        // from the leftmost digit to rightmost digit
        // current digit can take at most min(limit, curDigit)
        // and all the following bits
        for (int i = 0; i < preLen; i++) {
            if (limit < (f[i] - '0')) {
                count += (long long) pow(limit + 1, preLen - i);
                return count;
            }
            count += (long long) (f[i] - '0') * (long long) pow(limit + 1, preLen - 1 - i);
        }

        // the case from preLen to the end
        if (suffix >= s) {
            count++;
        }

        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countPowerful(to_string(finish), limit, s) - countPowerful(to_string(start - 1), limit, s);
    }
};
