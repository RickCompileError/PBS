// Time: O(n), Space: O(n)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        vector<int> comp;

        for (int i = 1, j = 0; i < sz; i++) {
            if (nums[i] == nums[j]) {
                continue;
            }
            comp.push_back((nums[i] > nums[j] ? 1 : -1));
            j = i;
        }

        sz = comp.size();
        for (int i = 1; i < sz; i++) {
            ans += comp[i] != comp[i - 1];
        }

        return ans;
    }
};
