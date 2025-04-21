// Time: O(n), Space: O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long base, mx, mn;
        base = mx = mn = 0;
        for (auto& dif: differences) {
            base += dif;
            mx = max(mx, base);
            mn = min(mn, base);
        }

        return max((upper - lower) - (mx - mn) + 1, (long long)0);
    }
};
