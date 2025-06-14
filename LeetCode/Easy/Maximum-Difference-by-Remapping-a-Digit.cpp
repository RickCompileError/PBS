// Time: O(100*n), Space: O(1)
class Solution {
public:
    int minMaxDifference(int num) {
        string snum = to_string(num);
        int sz = snum.size();
        int ans = -1;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                string mx = snum;
                string mn = snum;
                for (int k = 0; k < sz; k++) {
                    if (mx[k] == '0' + i) {
                        mx[k] = '9';
                    }
                    if (mn[k] == '0' + j) {
                        mn[k] = '0';
                    }
                }
                ans = max(ans, stoi(mx) - stoi(mn));
            }
        }

        return ans;
    }
};
