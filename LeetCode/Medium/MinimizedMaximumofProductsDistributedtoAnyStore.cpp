class Solution {
public:
    bool isPossible(int n, vector<int>& quantities, int m) {
        int store = 0;
        for (auto i : quantities) {
            store += (i / m) + (i % m != 0);
            if (store > n)
                return false;
        }
        return store <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e5, m, ans = -1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (isPossible(n, quantities, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
