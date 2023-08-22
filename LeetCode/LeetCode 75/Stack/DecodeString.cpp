// Time: O(n), Space: O(n)
// No stack version
class Solution {
public:
    int getDigitLength(string s) {
        int len = 0;
        while (isdigit(s[len])) len++;
        return len;
    }

    int getBracketLength(string s) {
        int leftBracket = 0;
        for (int i = 0, sz = s.size(); i < sz; i++) {
            if (s[i] == '[') leftBracket++;
            if (s[i] == ']') leftBracket--;
            if (leftBracket == 0) return i + 1;
        }
        return s.size();
    }

    string decodeString(string s) {
        string ans = "";
        for (int i = 0, sz = s.size(); i < sz;) {
            if (isalpha(s[i])) ans += s[i++];
            else if (isdigit(s[i])) {
                int digitLength = getDigitLength(s.substr(i));
                int times = stoi(s.substr(i, digitLength));
                i += digitLength;
                int bracketLength = getBracketLength(s.substr(i));
                string substr = decodeString(s.substr(i+1, bracketLength-2));
                i += bracketLength;
                while (--times >= 0) ans += substr;
            }
        }
        return ans;
    }
};
// Time: O(n), Space: O(n)
// Stack version
class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> timeStack;
        string str = "", tmp;
        int times = 0;
        for (int i = 0, sz = s.size(); i < sz; i++) {
            if (isdigit(s[i])) times = times * 10 + (s[i] - 48);
            else if (s[i] == '[') {
                timeStack.push(times);
                strStack.push(str);
                times = 0;
                str = "";
            } else if (s[i] == ']') {
                tmp = str;
                times = timeStack.top();
                timeStack.pop();
                str = strStack.top();
                strStack.pop();
                while (times > 0) str += tmp, times--;
            } else {
                str += s[i];
            }
        }
        return str;
    }
};