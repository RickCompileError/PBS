// Time: O(nlogn), Space: O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int sz = nums.size();
        int mn = 0;
        int mx = 0;
        int right = sz - 1;

        sort(nums.begin(), nums.end());

        while (right > mn) {
            while (mx < right && nums[mx] + nums[right] <= upper) {
                mx++;
            }

            while (mn < right && nums[mn] + nums[right] < lower) {
                mn++;
            }

            ans += min(right, mx) - mn;
            right--;
        }

        return ans;
    }
};

// We can exchange the problem, find the pairs at most k
// And the question answer will be atMost(upper) - atMost(lower - 1)
// Time: O(n), Space: O(1)
class Solution {
private:
    long long countAtMost(vector<int>& nums, int limit) {
        int l = 0;
        int r = nums.size() - 1;
        long long count = 0;

        while (l < r) {
            while (l < r && nums[l] + nums[r] > limit) {
                r--;
            }
            count += r - l;
            l++;
        }

        return count;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countAtMost(nums, upper) - countAtMost(nums, lower - 1);
    }
};
