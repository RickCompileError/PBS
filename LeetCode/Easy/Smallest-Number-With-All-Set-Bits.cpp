// Time: O(logn), Space: O(1)
class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (ans - 1 < n) {
            ans <<= 1;
        }
        return ans - 1;
    }
};
