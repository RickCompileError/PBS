// Time: O(n^2), Space: O(1)
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        int sz = word.size();
        string res;

        for (int i = 0; i < sz; i++) {
            res = max(res, word.substr(i, min(sz - numFriends + 1, sz - i)));
        }

        return res;
    }
};

// Time: O(n), Space: O(1)
class Solution {
private:
    string lastSubstring(string s) {
        int i = 0, j = 1, sz = s.size();

        while (j < sz) {
            int k = 0;
            while (j + k < sz && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < sz && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }

        return s.substr(i, sz - i);
    }

public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        string last = lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n - numFriends + 1));
    }
};
