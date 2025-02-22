// Time: O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        int sz = nums.size();
        for (int i = 0; i < sz && i <= right && right < sz; i++) {
            if (right >= sz - 1 || i > right) {
                break;
            }
            right = max(right, i + nums[i]);
        }

        return right >= sz - 1;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
