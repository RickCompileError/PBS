// Time: O(n), Space: O(1)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int sz = words.size();
        vector<string> ans(1);
        ans[0] = words[0];

        for (int i = 1; i < sz; i++) {
            if (groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
