// Time: O(n^2 as 1000), Space: O(n)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sz = s.size();
        int zero = 0;
        string sub = "";

        for (auto& c: s) {
            sub.push_back(c);
            while (sub.size() && stoll(sub, nullptr, 2) > k) {
                if (sub[0] == '0') {
                    zero++;
                }
                sub = sub.substr(1);
            }
        }

        return max(1, zero + (int)sub.size());
    }
};

// Time: O(n^2 as 32), Space: O(n)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sz = s.size();
        int one = 0;

        if (sz > 32) {
            one += count(s.begin(), s.end() - 32, '1');
        }

        s = s.substr(max(0, sz - 32));
        int nsz = s.size();
        for (int i = 0; i < nsz; i++) {
            if (s[i] == '0') {
                continue;
            }
            if (stoll(s, nullptr, 2) > k) {
                s[i] = '0';
                one++;
            }
        }

        return max(1, sz - one);
    }
};

// Time: O(n), Space: O(1)
int longestSubsequence(string s, int k) {
    int val = 0, cnt = 0, pow = 1;
    for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
        if (s[i] == '1') {
            ++cnt;
            val += pow;
        }
        pow <<= 1;
    }
    return count(begin(s), end(s), '0') + cnt;
}

// Time: O(n^2), Space: O(n), time limited
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sz = s.size();
        vector<string> dp(sz + 1);
        dp[0] = "";

        for (int i = 1; i <= sz; i++) {
            dp[i] = dp[i - 1] + s[i - 1];
            for (int j = i - 1; j > 0; j--) {
                dp[j] = min(dp[j], dp[j - 1] + s[i - 1]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= min(sz, 33); i++) {
            if (stoll(dp[i], nullptr, 2) <= k) {
                ans = i;
            }
        }

        return ans;
    }
};
