// Time: O(n), Space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int l = 0, r = 0;
        int goal = nums.size() - 1;

        while (r < goal) {
            int nxtR = r;

            for (int i = l; i <= r; i++) {
                nxtR = max(nxtR, i + nums[i]);
            }

            l = r + 1;
            r = nxtR;
            step++;
        }

        return step;
    }
};
