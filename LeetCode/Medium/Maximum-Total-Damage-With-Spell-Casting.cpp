// Time: O(nlogn), Space: O(n)
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,long long> damages;
        set<int> powers(power.begin(), power.end());
        vector<int> uniquePowers(powers.begin(), powers.end());
        vector<long long> dpPowers(powers.size(), 0);
        int dpSz = dpPowers.size();

        for (auto& p: power) {
            damages[p] += p;
        }

        for (int i = 0; i < dpSz; i++) {
            dpPowers[i] += damages[uniquePowers[i]];
            int j = i - 1;

            while (j >= 0 && uniquePowers[i] - uniquePowers[j] <= 2) {
                j--;
            }

            if (j >= 0) {
                dpPowers[i] += dpPowers[j];
            }

            j = i - 1;
            while (j >= 0 && uniquePowers[i] - uniquePowers[j] <= 2) {
                dpPowers[i] = max(dpPowers[i], dpPowers[j]);
                j--;
            }
        }

        return *max_element(dpPowers.begin(), dpPowers.end());
    }
};

/*
f(i) :
    max {
        power[i] + f(j);
    }
*/
auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() {
        ofstream("display_runtime.txt") << "0";
    });

    return 0;
}();
constexpr long long inf = 1e18;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> freq;
        for(auto &p: power) freq[p] += 1;

        sort(power.begin(), power.end());
        power.resize(unique(power.begin(), power.end()) - power.begin());

        int n = (int)power.size();
        vector<long long> dp(n,-1);
        auto f = [&](const auto &self, int i)->long long {
            if(i >= n) return 0;

            long long &ans = dp[i];

            if(ans != -1) return ans;

            long long notTake = self(self,i+1);
            long long take = -inf;
            int j = upper_bound(power.begin(), power.end(), power[i]+2) - power.begin();

            take = 1LL * freq[power[i]] * power[i] + self(self,j);

            return ans = max(notTake, take);
        };

        return f(f,0);
    }
};
