// Time: O(n), Space: O(1)
class Solution {
public:
    int maxDifference(string s) {
        int alphaCount[26]{};

        for (auto& c: s) {
            alphaCount[c - 'a']++;
        }

        int mxOdd = 0, mnEven = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (alphaCount[i] == 0) {
                continue;
            }
            if (alphaCount[i] & 1) {
                mxOdd = max(mxOdd, alphaCount[i]);
            } else {
                mnEven = min(mnEven, alphaCount[i]);
            }
        }

        return mxOdd - mnEven;
    }
};
