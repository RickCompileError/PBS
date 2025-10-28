// Time: O(n^2), Space: O(1)
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            int sz = s.size();
            for (int i = 1; i < sz; i++) {
                s[i - 1] = ((s[i - 1] - '0') + (s[i] - '0')) % 10 + '0';
            }
            s.pop_back();
        }
        return s[0] == s[1];
    }
};
