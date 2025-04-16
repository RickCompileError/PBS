// Time: O(n^2), Space: O(n), Time Limit Exceeded
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int ans = 0;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            unordered_map<int,int> um;
            int good = 0;
            int idx = i;

            for (; idx < sz; idx++) {
                good += (++um[nums[idx]] - 1);
                if (good >= k) {
                    break;
                }
            }
            ans += sz - idx;
        }

        return ans;
    }
};

// Sliding Windows, Time: O(n), Space: O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int sz = nums.size();
        int good = 0;
        int l = 0;
        int r = 0;
        unordered_map<int,int> um;

        while (r < sz) {
            while (r < sz && good < k) {
                um[nums[r]]++;
                good += (um[nums[r]] - 1);
                r++;
            }

            while (l < r && good >= k) {
                ans += sz - r + 1;
                good -= (um[nums[l]] - 1);
                um[nums[l]]--;
                l++;
            }
        }

        return ans;
    }
};

// Optimal
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int sz = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> um;

        while (r < sz) {
            k -= um[nums[r++]]++;

            while (k <= 0) {
                k += --um[nums[l++]];
            }

            ans += l;
        }

        return ans;
    }
};
