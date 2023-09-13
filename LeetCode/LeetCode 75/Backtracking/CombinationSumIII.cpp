// Time: O(2^n), Space: O(n)
class Solution {
public:

    void backtracking(vector<vector<int>>& ans, vector<int> cur, int k, int n, int sum = 0, int num = 1) {
        if (num == 10 && cur.size() < k) return;
        if (cur.size() == k) {
            if (sum == n) ans.push_back(cur);
            return;
        }

        cur.push_back(num);
        backtracking(ans, cur, k, n, sum + num, num + 1);
        cur.pop_back();
        backtracking(ans, cur, k, n, sum, num + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        backtracking(ans, {}, k, n);
        return ans;
    }
};

// version 2, fewer parameters
class Solution {
public:

    void backtracking(vector<vector<int>>& ans, vector<int>& cur, int k, int n, int idx = 1) {
        if (k == 0) {
            if (n == 0) ans.push_back(cur);
            return;
        }

        if (idx == 10) return;
        
        if (n >= idx) {
            cur.push_back(idx);
            backtracking(ans, cur, k - 1, n - idx, idx + 1);
            cur.pop_back();
            backtracking(ans, cur, k, n, idx + 1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        backtracking(ans, v, k, n);
        return ans;
    }
};

// version 3, the fatest
class Solution {
public:

    void backtracking(vector<vector<int>>& ans, vector<int>& cur, int k, int n, int idx = 1) {
        if (k == 0) {
            if (n == 0) ans.push_back(cur);
            return;
        }

        for (int i = idx; i < 10; i++) {
            if (n < i) break;
            cur.push_back(i);
            backtracking(ans, cur, k - 1, n - i, i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        backtracking(ans, v, k, n);
        return ans;
    }
};