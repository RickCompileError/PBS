// Tiem: O(n), Space: O(n)
class Solution {
private:
    int manacher(string s) {
        string ds = "#";
        for (auto& i: s) {
            ds += string(1, i) + "#";
        }
        int sz = ds.size();
        int l = 0, r = 0;
        vector<int> radius(sz, 0);

        for (int i = 0; i < sz; i++) {
            radius[i] = i < r ? min(r - i, radius[l + (r - i)]) : 0;
            while (i - radius[i] - 1 >= 0 && i + radius[i] + 1 < sz &&
                (ds[i - radius[i] - 1] == ds[i + radius[i] + 1])) {
                radius[i]++;
            }
            if (i + radius[i] > r) {
                l = i - radius[i];
                r = i + radius[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < sz; i++) {
            ans += radius[i] / 2;
        }
        
        return ans + s.size();
    }

public:
    int countSubstrings(string s) {
        return manacher(s);
    }
};
