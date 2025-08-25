// Time: O(n^2), Space: O(1)
class Solution {
private:
    string runLengthEncoding(string str) {
        char ch = str[0];
        int counter = 0;
        string res = "";

        for (auto& c: str) {
            if (c == ch) {
                counter++;
            } else {
                res += to_string(counter) + ch;
                ch = c;
                counter = 1;
            }
        }
        res += to_string(counter) + ch;

        return res;
    }

public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            ans = runLengthEncoding(ans);
        }
        return ans;
    }
};

// Optimized
class Solution {
private:
    string runLengthEncoding(int n, string str) {
        if (n == 0) {
            return str;
        }

        char ch = str[0];
        int counter = 0;
        string res = "";
        str += '&';

        for (auto& c: str) {
            if (c == ch) {
                counter++;
            } else {
                res += to_string(counter) + ch;
                ch = c;
                counter = 1;
            }
        }

        return runLengthEncoding(n - 1, res);
    }

public:
    string countAndSay(int n) {
        return runLengthEncoding(n - 1, "1");
    }
};
