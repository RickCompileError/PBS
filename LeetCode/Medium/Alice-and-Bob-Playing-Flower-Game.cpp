// Time: O(n), Space: O(n)
class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long)((n + 1) / 2) * (long long)(m / 2) + (long long)(n / 2) * (long long)((m + 1) / 2);
    }
};
