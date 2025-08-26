// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int sz = words.size();
        vector<int> ans;

        for (int i = 0; i < sz; i++) {
            for (auto& ch: words[i]) {
                if (ch == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
