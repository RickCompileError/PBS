// Time: O(1), Space: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remainDay = n % 7;
        // a1 + an + (n-1)*d * n / 2
        int money = weeks * 28 + weeks * (weeks - 1) / 2 * 7;

        for (int i = 1; i <= remainDay; i++) {
            money += i + weeks;
        }

        return money;
    }
};
