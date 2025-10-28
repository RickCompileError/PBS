// Time: O(n), Space: O(1)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sz = nums.size();
        int leftVal = 0, rightVal = 0, curr = -1;

        for (int i = 0; i < sz; i++) {
            if (nums[i] == 0 && curr == -1) {
                curr = i;
                continue;
            }
            if (curr == -1) {
                leftVal += nums[i];
            } else {
                rightVal += nums[i];
            }
        }

        int validAns = 0;

        while (curr < sz) {
            if (leftVal == rightVal) {
                validAns += 2;
            } else if (abs(leftVal - rightVal) == 1) {
                validAns += 1;
            }
            while (++curr < sz && nums[curr] != 0) {
                leftVal += nums[curr];
                rightVal -= nums[curr];
            }
        }

        return validAns;
    }
};
