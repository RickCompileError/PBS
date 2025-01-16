// Time: O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int base = 1;
        while (base <= n) {
            int num = 1;
            while (num <= n) {
                ans[num] += (base & num) > 0;
                num++;
            }
            base <<= 1;
        }
        return ans;
    }
};

// Time: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + i % 2;
        }
        return ans;
    }
};
