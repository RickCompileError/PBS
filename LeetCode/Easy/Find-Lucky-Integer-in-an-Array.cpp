// Time: O(n), Space: O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        int mx = -1;

        for (auto& i: arr) {
            freq[i]++;
        }
        for (auto& [k, v]: freq) {
            if (k == v) {
                mx = max(mx, k);
            }
        }

        return mx;
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int sz = arr.size();

        for (auto n: arr) {
            n &= 0xffff;
            if (n <= sz) {
                arr[n - 1] += 0x10000;
            }
        }
        for (int i = sz; i > 0; i--) {
            if ((arr[i - 1] >> 16) == i) {
                return i;
            }
        }

        return -1;
    }
};
