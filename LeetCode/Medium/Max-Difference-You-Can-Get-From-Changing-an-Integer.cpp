// Time: O(n), Space: O(1)
class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;
        int sz = a.size();
        size_t mxPos = a.find_first_not_of('9');
        size_t mnPos = b.find_first_not_of("01");

        if (mxPos != string::npos) {
            char c = a[mxPos];
            replace(a.begin(), a.end(), c, '9');
        }
        if (mnPos != string::npos) {
            char c = b[mnPos];
            if (mnPos == 0) {
                replace(b.begin(), b.end(), c, '1');
            } else {
                replace(b.begin(), b.end(), c, '0');
            }
        }

        return stoi(a) - stoi(b);
    }
};
