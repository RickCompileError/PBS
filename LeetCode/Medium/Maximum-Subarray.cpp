// Time: O(n), Space: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz, 0);
        ans[0] = nums[0];
        int mx = ans[0];

        for (int i = 1; i < sz; i++) {
	    ans[i] = max(nums[i], ans[i - 1] + nums[i]);
	    mx = max(mx, ans[i]);
        }

        return mx;
    }
};

// Kadne's Algorithm, Time: O(n), Space: O1)
class Solution {
private:

public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, cur = 0;
        for (auto& num: nums) {
            if (cur < 0) {
                cur = 0;
            }
            cur += num;
            ans = max(ans, cur);
        }

        return ans;
    }
};

// Divide And Conquer, Time: O(nlogn), Space: O(logn)
class Solution {
private:
    int divideAndConquer(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }

        int m = (l + r) >> 1;
        int lSum{0}, rSum{0}, cur{0};
        
        for (int i = m - 1; i >= l; i--) {
            cur += nums[i];
            lSum = max(lSum, cur);
        }
        cur = 0;
        for (int i = m + 1; i <= r; i++) {
            cur += nums[i];
            rSum = max(rSum, cur);
        }

        return max(divideAndConquer(nums, l, m - 1),
                max(divideAndConquer(nums, m + 1, r),
                    lSum + nums[m] + rSum));
    }

public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }
};
