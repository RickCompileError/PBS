// Time: O(logn), Space: O(1)
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber--) {
            ans = (char)('A' + columnNumber % 26) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};