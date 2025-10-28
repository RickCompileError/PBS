// Time: O(n), Space: O(1)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mxSum = 0;
        int mxNonPos = INT_MIN;
        unordered_set<int> exists;

        for (auto& num: nums) {
            if (num <= 0) {
                mxNonPos = max(mxNonPos, num);
                continue;
            }
            if (exists.find(num) == exists.end()) {
                exists.insert(num);
                mxSum += num;
            }
        }

        return mxSum == 0 ? mxNonPos : mxSum;
    }
};
