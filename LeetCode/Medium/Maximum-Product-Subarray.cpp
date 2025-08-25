// Kadane's Algorithm, Time: O(n), Space: O(1)
#define ll long long
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll ans = LONG_LONG_MIN;
        ll mxProd = 1;
        ll mnProd = 1;

        for (auto& i: nums) {
            ll mxTmp = mxProd * i;
            ll mnTmp = mnProd * i;
            mxProd = max(max(mxTmp, mnTmp), (ll)i);
            mnProd = min(min(mxTmp, mnTmp), (ll)i);
            ans = max(ans, mxProd);
            cout <<mxProd <<' ' <<mnProd <<endl;
        }

        return ans;
    }
};

// Prefix & Suffix, Time: O(n), Space: O(1)
#define ll long long
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll sz = nums.size(), ans = nums[0];
        ll prefix = 1, suffix = 1;

        for (int i = 0; i < sz; i++) {
            prefix = nums[i] * (prefix ? prefix : 1);
            suffix = nums[sz - 1 - i] * (suffix ? suffix : 1);
            ans = max(max(prefix, suffix), ans);
        }

        return ans;
    }
};
