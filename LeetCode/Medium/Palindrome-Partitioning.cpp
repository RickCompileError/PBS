// Cache version, Time: O(n*2^n), Space: O(2^n)
class Solution {
private:
    vector<vector<string>> res;
    unordered_map<string, int> cache;
    int sz;

    bool isPalindrome(string s) {
        if (cache[s] != 0) {
            return cache[s] == 1 ? true : false;
        }

        int sLen = s.size();
        int half = s.size() / 2;
        for (int i = 0; i < half; i++) {
            if (s[i] != s[sLen - i - 1]) {
                cache[s] = -1;
                return false;
            }
        }

        cache[s] = 1;
        return true;
    }

    void backtracking(string s, int idx, vector<string>& comb) {
        if (idx == sz) {
            res.push_back(comb);
            return;
        }

        int len = sz - idx;
        for (int i = 1; i <= len; i++) {
            string sub = s.substr(idx, i);
            if (!isPalindrome(sub)) {
                continue;
            }
            comb.push_back(sub);
            backtracking(s, idx + i, comb);
            comb.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        sz = s.size();
        vector<string> comb;
        backtracking(s, 0, comb);
        return res;
    }
};

// DP with Backtracking, Time: O(n*2^n), Space: O(n^2)
class Solution {
private:
    int sz;
    vector<vector<string>> res;

    void backtracking(string& s, int idx, vector<string>& comb, vector<vector<bool>>& dp) {
        if (idx == sz) {
            res.push_back(comb);
            return;
        }

        for (int len = 1; len <= sz - idx; len++) {
            if (dp[idx][idx + len - 1]) {
                comb.push_back(s.substr(idx, len));
                backtracking(s, idx + len, comb, dp);
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        sz = s.size();
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));

        for (int len = 1; len <= sz; len++) {
            for (int startIdx = 0; startIdx <= sz - len; startIdx++) {
                int lastIdx = startIdx + len - 1;
                dp[startIdx][lastIdx] = (s[startIdx] == s[lastIdx]) &&
                                        (startIdx + 1 > lastIdx - 1 ||
                                        dp[startIdx + 1][lastIdx - 1]);
            }
        }

        vector<string> partition;
        backtracking(s, 0, partition, dp);

        return res;
    }
};
