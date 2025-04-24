// Time: O(n), Space: O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int tot_distinct = unordered_set<int>(nums.begin(), nums.end()).size();
        int sz = nums.size();
        int ans = 0;
        unordered_map<int,int> repeat;

        for (int l = 0, r = 0; r < sz; r++) {
            repeat[nums[r]]++;

            while (repeat.size() == tot_distinct) {
                ans += sz - r;
                repeat[nums[l]]--;
                if (repeat[nums[l]] == 0) repeat.erase(nums[l]);
                l++;
            }
        }

        return ans;
    }
};
