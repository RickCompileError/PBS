// Time: O(nlogn), Space: O(1)
class Solution {
private:
    bool isSymmetric(int num) {
        string s = to_string(num);
        int sz = s.size();

        if (sz % 2) {
            return false;
        }

        int sum = 0;
        for (int i = 0, j = sz / 2; j < sz; i++, j++) {
            sum += s[i] - s[j];
        }

        return sum == 0;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (; low <= high; low++) {
            if (isSymmetric(low)) {
                count++;
            }
        }

        return count;
    }
};
