// Time: O(n), Space: O(n)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int sz = s.size();

        for (int i = 0; i < sz; i += k) {
            ans.push_back(s.substr(i, k));
        }
        while (ans.back().size() < k) {
            ans.back().push_back(fill);
        }

        return ans;
    }
};
