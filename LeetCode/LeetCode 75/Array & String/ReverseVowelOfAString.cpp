// Complexity: O(n), Space: O(1)
class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        string ans = "";
        int sz = s.size();
        for (int i = 0, j = sz - 1; i < sz || j >= 0;){
            while (i < sz && !isVowel(s[i])) ans += s[i], i++;
            while (j >= 0 && !isVowel(s[j])) j--;
            if (j >= 0) ans += s[j], i++, j--;
        }
        return ans;
    }
};