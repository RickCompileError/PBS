// Time: O(n), Space: O(n)
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rs = s;
        reverse(rs.begin(), rs.end());
        return s == rs;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int sz = s.size();
        for (int l = 0, r = sz - 1; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }

        return true;
    }
};
