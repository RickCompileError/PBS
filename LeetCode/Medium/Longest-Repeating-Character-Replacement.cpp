// O(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> alp;
        int l = 0, r = 0, sz = s.size(), maxRepeat = 0, ans = 0;

        while (r < sz) {
            alp[s[r]] += 1;
            maxRepeat = max(maxRepeat, alp[s[r]]);

            if (r - l + 1 - maxRepeat > k) {
                alp[s[l]]--;
                l++;
            } else {
                ans = max(ans, r - l + 1);
            }
            r++;
        }

        return ans;
    }
};
