class Solution {
private:
    int opt(int l, int r, char op) {
        switch (op) {
            case '+':
                return l + r;
            case '-':
                return l - r;
            case '*':
                return l * r;
            case '/':
                return l / r;
            default:
                return 0;
        }
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> val;
        int l, r;
        for (auto& s: tokens) {
            if (isdigit(s.back())) {
                val.push(stoi(s));
            } else {
                r = val.top();
                val.pop();
                l = val.top();
                val.pop();
                val.push(opt(l, r, s[0]));
            }
        }

        return val.top();
    }
};
