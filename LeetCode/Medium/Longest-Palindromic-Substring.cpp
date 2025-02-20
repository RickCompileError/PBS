// Time: O(n^2), Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();

        int mxLen = 0, mxIdx = -1;

        for (int i = 0; i < sz; i++) {
            int oddL, oddR, evenL, evenR;
            oddL = oddR = evenL = i;
            evenR = i + 1;

            while (oddL >= 0 && oddR < sz && s[oddL] == s[oddR]) {
                oddL--;
                oddR++;
            }

            while (evenL >= 0 && evenR < sz && s[evenL] == s[evenR]) {
                evenL--;
                evenR++;
            }

            if (oddR - oddL - 1 > mxLen) {
                mxLen = oddR - oddL - 1;
                mxIdx = min(oddL + 1, i);
            }

            if (evenR - evenL - 1 > mxLen) {
                mxLen = evenR - evenL - 1;
                mxIdx = min(evenL + 1, i);
            }
        }

        return s.substr(mxIdx, mxLen);
    }
};

// Manacher's Algorithm, Time: O(n), Space: O(n)
class Solution {
private:
    vector<int> manacher(string& s) {
        string ds = "#";
        for (auto& c: s) {
            ds.push_back(c);
            ds.push_back('#');
        }

        int sz = ds.size();
        int l{0}, r{0};
        vector<int> radius(sz, 0);

        for (int i = 0; i < sz; i++) {
            radius[i] = i < r ? min(r - i, radius[l + (r - i)]) : 0;
            while (i - radius[i] - 1 >= 0 && i + radius[i] + 1 < sz &&
                (ds[i - radius[i] - 1] == ds[i + radius[i] + 1])) {
                radius[i]++;
            }
            if (i + radius[i] > r) {
                l = i - radius[i];
                r = i + radius[i];
            }
        }

        return radius;
    }

public:
    string longestPalindrome(string s) {
        vector<int> dp = manacher(s);
        int sz = dp.size();
        int center = 0, radius = 0;
        for (int i = 0; i < sz; i++) {
            cout <<dp[i] <<' ';
        }

        for (int i = 1; i < sz; i++) {
            if (dp[i] > dp[center]) {
                center = i;
                radius = dp[i];
            }
        }

        return s.substr((center - radius) / 2, radius);
    }
};
