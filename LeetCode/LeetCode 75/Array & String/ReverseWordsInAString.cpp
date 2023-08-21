// Complexity: O(n), Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int left, right = s.size() - 1;
        while (right >= 0) {
            while (right >= 0 && !isalnum(s[right])) right--;
            left = right;
            while (left >= 0 && isalnum(s[left])) left--;
            if (right < 0) break;
            if (ans != "") ans += " ";
            ans += s.substr(left + 1, right - left);
            right = left;
        }
        return ans;
    }
};

// Complexity: O(n), Space: O(1)
// Another version
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int left, right;
        for (int i = s.size() - 1; i >= 0;) {
            while (i >= 0 && !isalnum(s[i])) i--;
            right = i;
            while (i >= 0 && isalnum(s[i])) i--;
            left = i;
            if (right < 0) break;
            if (ans != "") ans += " ";
            ans += s.substr(left + 1, right - left);
        }
        return ans;
    }
};