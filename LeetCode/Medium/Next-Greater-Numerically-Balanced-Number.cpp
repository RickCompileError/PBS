// Time: O(m^n) Space: O(n)
// Optimize: the maximum length of possible answer is log10(num) + 1
class Solution {
private:
    void generate(int num, vector<int>& count, vector<int>& list) {
        if (num > 0 && isBeautiful(count)) {
            list.push_back(num);
        }

        if (num > 1224444) {
            return;
        }

        for (int d = 1; d <= 7; d++) {
            if (count[d] < d) {
                count[d]++;
                generate(num * 10 + d, count, list);
                count[d]--;
            }
        }
    }

    bool isBeautiful(vector<int>& count) {
        for (int i = 1; i <= 7; i++) {
            if (count[i] != 0 && count[i] != i) {
                return false;
            }
        }

        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        vector<int> list;
        vector<int> count(10, 0);

        generate(0, count, list);
        sort(list.begin(), list.end());
        
        return *upper_bound(list.begin(), list.end(), n);
    }
};
