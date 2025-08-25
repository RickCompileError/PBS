// Time: O(3^(m+n)), Space: O(m+n)
class Solution {
private:
    int dfs(string& w1, string& w2, int i1, int i2) {
        if (i1 == w1.size()) {
            return w2.size() - i2;
        }

        if (i2 == w2.size()) {
            return w1.size() - i1;
        }

        if (w1[i1] == w2[i2]) {
            return dfs(w1, w2, i1 + 1, i2 + 1);
        }

        int insert = dfs(w1, w2, i1, i2 + 1);
        int remove = dfs(w1, w2, i1 + 1, i2);
        int modify = dfs(w1, w2, i1 + 1, i2 + 1);

        return 1 + min(insert, min(remove, modify));
    }

public:
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }
};

// Time: O(m*n), Space: O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();

        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

        for (int i = 0; i <= sz1; i++) {
            dp[i][sz2] = sz1 - i;
        }

        for (int j = 0; j <= sz2; j++) {
            dp[sz1][j] = sz2 - j;
        }

        for (int i = sz1 - 1; i >= 0; i--) {
            for (int j = sz2 - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
                }
            }
        }

        return dp[0][0];
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

        for (int i = 1; i <= sz1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= sz2; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= sz1; i++) {
            for (int j = 1; j <= sz2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j]++;
            }
        }

        return dp[sz1][sz2];
    }
};

// It has a optimal version, Time: O(m*n), Space: O(min(m,n))
