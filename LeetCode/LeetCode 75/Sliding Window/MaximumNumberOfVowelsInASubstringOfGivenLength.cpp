// Time: O(n), Memory: O(1)
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int ans = INT_MIN, tmp = 0;
        for (int i = 0, sz = s.size(); i < sz; i++) {
            tmp += isVowel(s[i]);
            if (i >= k) tmp -= isVowel(s[i-k]);
            ans = max(ans, tmp);
        }
        return ans;
    }
};