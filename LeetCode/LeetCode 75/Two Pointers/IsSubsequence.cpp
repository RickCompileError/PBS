// Time: O(n), Memory: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sSz = s.size(), tSz = t.size(), i = 0, j = 0;
        if (sSz > tSz) return false;
        while (i < sSz && j < tSz) {
            while (j < tSz && s[i] != t[j]) j++;
            if (j < tSz) i++, j++;
        }
        return i == sSz;
    }
};