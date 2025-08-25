// O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int start = 0;
        int ans = 0;
        int sz = s.size();

        for (int i = 0; i < sz; i++) {
            while (us.find(s[i]) != us.end()) {
                us.erase(s[start++]);
            }
            us.insert(s[i]);
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
