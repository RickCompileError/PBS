// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> count(10,0);

        for (auto& digit: digits) {
            count[digit]++;
        }

        for (int i = 100; i < 1000; i += 2) {
            vector<int> sep(10,0);
            int tmp = i;
            while (tmp > 0) {
                sep[tmp % 10]++;
                tmp /= 10;
            }

            bool legal = true;
            for (int j = 0; j < 10 && legal; j++) {
                if (sep[j] > count[j]) {
                    legal = false;
                }
            }

            if (legal) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
