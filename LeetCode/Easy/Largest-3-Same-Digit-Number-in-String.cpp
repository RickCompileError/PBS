// Time: O(n), Space: O(1)
class Solution {
public:
    string largestGoodInteger(string num) {
        char mxDigit = 0;
        char digit = 0;
        int counter = 0;
        int sz = num.size();

        for (int i = 0; i < sz; i++) {
            if (digit != num[i]) {
                digit = num[i];
                counter = 1;
            } else {
                counter++;
                if (counter >= 3) {
                    mxDigit = max(mxDigit, digit);
                }
            }
        }

        return mxDigit == 0 ? "" : string(3, mxDigit);
    }
};
