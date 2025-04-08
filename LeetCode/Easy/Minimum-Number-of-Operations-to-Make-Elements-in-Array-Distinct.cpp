// Time: O(n), Space: O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int duplicate = nums.size() - 1;
        unordered_set<int> us;

        for (; duplicate >= 0; duplicate--) {
            if (us.find(nums[duplicate]) != us.end()) {
                break;
            }
            us.insert(nums[duplicate]);
        }

        return (duplicate + 3) / 3;
    }
};

// Optimized version
#define SZ 101
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int duplicate = nums.size() - 1;
        vector<bool> exist(SZ, false);

        for (; duplicate >= 0; duplicate--) {
            if (exist[nums[duplicate]]) {
                break;
            }
            exist[nums[duplicate]] = true;
        }

        return (duplicate + 3) / 3;
    }
};
