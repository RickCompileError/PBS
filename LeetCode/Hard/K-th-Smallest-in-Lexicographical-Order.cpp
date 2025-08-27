// Time: O(log10(n)), Space: O(1)
class Solution {
private:
    int calSteps(int& n, long long n1, long long n2) {
        int steps = 0;

        while (n1 <= n) {
            steps += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }

        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int steps = calSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }
};
