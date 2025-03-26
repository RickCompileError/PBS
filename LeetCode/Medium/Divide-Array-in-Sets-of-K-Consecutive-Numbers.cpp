// Time: O(nlogn), Space: O(1)
// This problem is the same as 846
class Solution {
private:
    bool findConsecutive(vector<int>& nums, int k, int idx, int sz) {
        int nxt = nums[idx] + 1;
        int count = 1;
        nums[idx++] = -1;

        while (idx < sz && count < k) {
            if (nums[idx] == nxt) {
                nxt++;
                count++;
                nums[idx] = -1;
            }
            idx++;
        }

        return count == k;
    }

public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int sz = nums.size();

        if (sz % k != 0) {
            return false;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < sz; i++) {
            if (nums[i] >= 0 && !findConsecutive(nums, k, i, sz)) {
                return false;
            }
        }

        return true;
    }
};
