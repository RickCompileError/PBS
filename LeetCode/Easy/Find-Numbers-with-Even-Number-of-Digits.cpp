// Time: O(n), Space: O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;

        for (auto& num: nums) {
            int digits = 0;
            while (num > 0) {
                digits++;
                num /= 10;
            }
            counter += !(digits & 1);
        }

        return counter;
    }
};
