// Time: O(n), Space: O(n)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        int sz = text.size();
        int wordStart = 0;
        unordered_set<char> us(brokenLetters.begin(), brokenLetters.end());

        for (int i = 0; i < sz; i++) {
            if (text[i] != ' ') {
                continue;
            }
            string tmp = text.substr(wordStart, i - wordStart);
            bool broke = false;
            for (auto& c: tmp) {
                if (us.count(c)) {
                    broke = true;
                }
            }
            ans += !broke;
            wordStart = i + 1;
        }
        string tmp = text.substr(wordStart);
        bool broke = false;
        for (auto& c: tmp) {
            if (us.count(c)) {
                broke = true;
            }
        }
        ans += !broke;

        return ans;

    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        int brokenCounter = 0;
        int sz = text.size();
        unordered_set<char> us(brokenLetters.begin(), brokenLetters.end());

        for (int i = 0; i < sz; i++) {
            if (text[i] == ' ') {
                ans += (brokenCounter == 0);
                brokenCounter = 0;
                continue;
            }
            brokenCounter += (us.count(text[i]) > 0);
        }

        return ans + (brokenCounter == 0);
    }
};
