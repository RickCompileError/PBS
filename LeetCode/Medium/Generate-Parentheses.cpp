// Backtracking, Time O(4^n*sqrt(n)), Space O((2n)!/((n+1)!n!))
class Solution {
private:
    vector<string> ans;
    void dp(string s, int leftP, int n) {
        if (n == 0) {
            while (leftP-- > 0) s += ")";
            ans.push_back(s);
            return;
        }

        dp(s + "(", leftP + 1, n - 1);
        if (leftP > 0) dp(s + ")", leftP - 1, n);
    }

public:
    vector<string> generateParenthesis(int n) {
        dp("", 0, n);
        return ans;
    }
};
