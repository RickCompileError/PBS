// Time: O(n), Space: O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int ch[26]{0};
        map<string,int> m;

        for (string& word: words) {
            if (word[0] == word[1]) {
                ch[word[0] - 'a']++;
                continue;
            }

            swap(word[0], word[1]);
            if (m[word]) {
                m[word]--;
                ans += 4;
                continue;
            }
            swap(word[0], word[1]);
            m[word]++;
        }

        bool mid = false;
        for (int i = 0; i < 26; i++) {
            if (ch[i] % 2) {
                mid = true;
            }
            ans += ch[i] / 2 * 4;
        }

        return ans + (mid ? 2 : 0);
    }
};
