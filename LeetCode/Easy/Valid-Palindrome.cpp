class Solution {
public:
    bool isPalindrome(string s) {
        string cvt = "";
        for (char& ch: s) {
            if (isalnum(ch)) {
                cvt += (ch + (isupper(ch) ? 32 : 0));
            }
        }

        int sz = cvt.size();
        string rcvt = cvt;
        reverse(cvt.begin(), cvt.end());

        return cvt == rcvt;
    }
};
