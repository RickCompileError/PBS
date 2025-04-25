// Time: O(n), Space: O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int equalK = 0;
        int reminder = 0;
        unordered_map<int,long long> um;
        um[0] = 1;

        for (auto& num: nums) {
            equalK += num % modulo == k;
            reminder = (equalK - k + modulo) % modulo;
            ans += um[reminder];
            um[equalK % modulo]++;
        }

        return ans;
    }
};
