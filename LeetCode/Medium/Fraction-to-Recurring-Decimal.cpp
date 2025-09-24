// Time: O(n), Space: O(n)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg = numerator < 0 ^ denominator < 0;
        long long num = numerator, den = denominator;
        num = abs(num);
        den = abs(den);

        string integer = to_string(num / den);
        num = num % den * 10;

        if (num == 0) {
            return (neg && integer != "0" ? "-" : "") + integer;
        }

        unordered_map<int, int> decimalIdx;
        string decimal = "";

        while (num != 0 && decimalIdx.find(num) == decimalIdx.end()) {
            decimal += to_string(num / den);
            decimalIdx[num] = decimalIdx.size();
            num = num % den * 10;
        }

        if (num) {
            decimal.insert(decimalIdx[num], "(");
            decimal.push_back(')');
        }

        return (neg ? "-" : "") + integer + "." + decimal;
    }
};
