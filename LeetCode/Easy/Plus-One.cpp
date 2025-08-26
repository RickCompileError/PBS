// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int res = 0;
        int idx = digits.size() - 1;
        digits[idx]++;

        do {
            digits[idx] += res;
            res = digits[idx] == 10;
            digits[idx--] %= 10;
        } while (res && idx >= 0);

        if (res) {
            digits.emplace(digits.begin(), res);
        }

        return digits;
    }
};
