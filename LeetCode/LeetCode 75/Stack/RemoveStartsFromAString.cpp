// Time: O(n), Space: O(1)
// String swap and varaible 'pos' simulate stack
class Solution {
public:
    string removeStars(string s) {
        int pos = 0;
        for (int i = 0, sz = s.size(); i < sz; i++) {
            if (s[i] == '*' && pos >= 0) pos--;
            if (s[i] != '*' && i != pos) swap(s[i], s[++pos]);
        }
        return s.substr(0, pos+1);
    }
};
// Time: O(n), Space: O(n)
// Stack version, Time limit exceeded
class Solution {
public:
    string removeStars(string s) {
        stack<char> sc;
        for (char i: s) {
            if (i == '*' && !sc.empty()) sc.pop();
            else if (i != '*') sc.push(i);
        }
        string ans = "";
        while (!sc.empty()) {
            ans = sc.top() + ans;
            sc.pop();
        }
        return ans;
    }
};
// Time: O(n), Space: O(1)
// String earse version, Time limit exceeded
class Solution {
public:
    string removeStars(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                s.erase(i--, 1);
                if (i >= 0) s.erase(i--, 1);
            }
        }
        return s;
    }
};