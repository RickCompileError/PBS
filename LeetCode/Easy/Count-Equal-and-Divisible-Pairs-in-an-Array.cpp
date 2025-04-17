// Two Pointers, Time: O(n^2), Space: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// Map & GCD, Time: O(n*sqrt(k)), Space: O(n)
class Solution {
private:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    vector<int> getDivisor(int k) {
        vector<int> div;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                div.push_back(i);
                if (i != k / i) {
                    div.push_back(k / i);
                }
            }
        }
        return div;
    }

public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int sz = nums.size();
        vector<int> div = getDivisor(k);
        unordered_map<int,vector<int>> um;

        for (int i = 0; i < sz; i++) {
            um[nums[i]].push_back(i);
        }

        for (auto& [key, val]: um) {
            unordered_map<int,int> counter;

            for (auto& i: val) {
                int gcdd = gcd(i, k);
                int quot = k / gcdd;
                ans += counter[quot];

                for (int d: div) {
                    if (i % d == 0) {
                        counter[d]++;
                    }
                }
            }
        }

        return ans;

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
