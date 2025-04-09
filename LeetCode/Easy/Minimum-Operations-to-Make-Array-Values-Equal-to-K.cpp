// Time: O(n), Space: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> us;
        for (auto& i: nums) {
            if (i < k) {
                return -1;
            }
            us.insert(i);
        }
        us.insert(k);
        return us.size() - 1;
    }
};
