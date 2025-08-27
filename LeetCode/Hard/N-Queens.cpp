// time: O(n!), space: O(n*n)
class Solution {
private:
    vector<vector<string>> ans;

    void createAns(vector<pair<int,int>>& v) {
        vector<string> board;
        for (auto& i: v) {
            int pos = i.second;
            string line = string(pos - 1, '.') + "Q" + string(v.size() - pos, '.');
            board.push_back(line);
        }
        ans.push_back(board);
    }

    bool check(vector<pair<int,int>>& v, pair<int,int>& p) {
        for (auto& i: v) {
            if (i.second == p.second || abs(i.first - p.first) == abs(i.second - p.second)) {
                return false;
            };
        }

        return true;
    }

    void backtracking(vector<pair<int,int>>& v, int n) {
        if (v.size() == n) {
            createAns(v);
            return;
        }

        for (int i = 1; i <= n; i++) {
            pair<int,int> p = {v.size() + 1, i};
            if (check(v, p)) {
                v.push_back(p);
                backtracking(v, n);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<pair<int,int>> v;
        backtracking(v, n);
        return ans;
    }
};
