// Time: O(m * n), Space: O(m + n)
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int sz1 = num1.size();
        int sz2 = num2.size();

        vector<int> v1, v2, v3;

        for (int i = sz1 - 1; i >= 0; i--) {
            v1.push_back(int(num1[i] - 48));
        }
        for (int i = sz2 - 1; i >= 0; i--) {
            v2.push_back(int(num2[i] - 48));
        }

        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                if (i + j >= v3.size()) {
                    v3.push_back(0);
                }
                v3[i + j] += v1[i] * v2[j];
            }
        }

        int carry = 0;
        int idx = 0;
        while (idx < v3.size() || carry > 0) {
            if (idx >= v3.size()) {
                v3.push_back(0);
            }
            v3[idx] += carry;
            carry = v3[idx] / 10;
            v3[idx] %= 10;
            idx++;
        }

        int sz3 = v3.size();
        string ans = "";
        for (int i = sz3 - 1; i >= 0; i--) {
            ans += (char)(v3[i] + 48);
        }

        return ans;
    }
};

// Simplify
// Time: O(m * n), Space: O(m + n)
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> res(num1.size() + num2.size(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int sz1 = num1.size();
        int sz2 = num2.size();
        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += mul;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        stringstream ans;
        int idx = res.size() - 1;
        while (idx >= 0 && res[idx] == 0) {
            idx--;
        }
        while (idx >= 0) {
            ans <<res[idx--];
        }
        return ans.str();
    }
};
