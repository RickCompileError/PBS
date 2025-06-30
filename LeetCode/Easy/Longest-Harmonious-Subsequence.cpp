// Time: O(n), Space: O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> um;

        for (auto& num: nums) {
            um[num]++;
        }

        int ans = 0;
        for (auto& [k, v]: um) {
            if (um[k - 1] > 0) {
                ans = max(ans, v + um[k - 1]);
            }
        }

        return ans;
    }
};
