// Two pass
// Time: O(n), Space: O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mxFreq = 0;
        map<int,int> freqs;

        for (auto& num: nums) {
            freqs[num]++;
            mxFreq = max(mxFreq, freqs[num]);
        }

        int ans = 0;
        for (auto& [k,v]: freqs) {
            if (v == mxFreq) {
                ans += v;
            }
        }

        return ans;
    }
};

// Exist one pass version
