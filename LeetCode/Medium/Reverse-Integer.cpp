class Solution {
public:
    int POS_BOUND = INT_MAX / 10;
    int NEG_BOUND = INT_MIN / 10;

    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res > POS_BOUND || res < NEG_BOUND) {
                return 0;
            }

            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }
};
