class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for (auto& i: s) {
            if (i == '(' || i =='[' || i == '{') {
                p.push(i);
            }
            else {
                if (p.empty() ||
                    (p.top() == '(' && i != ')') ||
                    (p.top() == '[' && i != ']') ||
                    (p.top() == '{' && i != '}')) return false;
                else p.pop();
            }
        }
        return p.empty();
    }
};