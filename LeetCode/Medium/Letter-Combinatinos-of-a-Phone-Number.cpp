// Time: O(n * 4^n), Space: O(n)
class Solution {
private:
    string alpha[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtracking(vector<string>& ans, string digits, int pos = 0, string now = "") {
        if (pos >= digits.size()) {
            ans.push_back(now);
            return;
        }
        for (char i: alpha[digits[pos] - '2']) {
            backtracking(ans, digits, pos + 1, now + i);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();
        vector<string> ans;
        backtracking(ans, digits);
        return ans;
    }
};
