// Trie solution, Time: O(n^2), Space: O(n + m * k), n = len(s), m = avglen(words), k = len(words)
class Trie {
public:
    bool word;
    unordered_map<char,Trie*> um;

    Trie() {
        word = false;
    }

    void addWord(string str) {
        Trie* node = this;
        for (char& ch: str) {
            if (node -> um[ch] == nullptr) {
                node -> um[ch] = new Trie();
            }
            node = node -> um[ch];
        }
        node -> word = true;
    }

    void find(string s, int idx, vector<bool>& dp) {
        Trie* node = this;
        int sz = s.size();

        for (; idx < sz; idx++) {
            if (node -> um[s[idx]] == nullptr) {
                return;
            }
            node = node -> um[s[idx]];
            if (node -> word) {
                dp[idx] = true;
            }
        }
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        for (auto& word: wordDict) {
            root -> addWord(word);
        }

        int sz = s.size();
        vector<bool> dp(sz);
        root -> find(s, 0, dp);
        for (int i = 1; i < sz; i++) {
            if (dp[i - 1] == true) {
                root -> find(s, i, dp);
            }
        }

        return dp[sz - 1];
    }
};

// DP bottom-up, Time: O(n*m*t), Space: O(n), n = len(str), m = len(words), t = avglen(words)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        vector<bool> dp(sz + 1, false);
        dp[sz] = true;

        for (int i = sz - 1; i >= 0; i--) {
            for (auto& word: wordDict) {
                if (i + word.size() <= sz &&
                    s.substr(i, word.size()) == word) {
                    dp[i] = dp[i + word.size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};
