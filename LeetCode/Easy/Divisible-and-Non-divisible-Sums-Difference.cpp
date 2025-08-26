// Time: O(1), Space: O(1)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n * (n + 1)) / 2;
        int quot = n / m;
        int num2 = m * (quot * (quot + 1)) / 2;
        return sum - 2 * num2;
    }
};
