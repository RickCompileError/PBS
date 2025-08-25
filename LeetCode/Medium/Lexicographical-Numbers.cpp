// Time: O(n), Space: O(1)
class Solution {
private:
    void dfs(int cur, int& n, vector<int>& lex) {
        if (cur > n) {
            return;
        }
        lex.push_back(cur);
        for (int i = 0; i < 10; i++) {
            dfs(cur * 10 + i, n, lex);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for (int i = 1; i < 10; i++) {
            dfs(i, n, ans);
        }

        return ans;
    }
};
