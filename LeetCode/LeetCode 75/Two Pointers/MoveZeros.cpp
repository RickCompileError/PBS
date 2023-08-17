// Time: O(n^2), Memory: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        for (int i = sz - 1; i >= 0; i--) {
            if (nums[i] != 0) continue;
            for (int j = i + 1; j < sz; j++) swap(nums[j], nums[j-1]);
        }
    }
};

// Time: O(n), Memory: O(1)
// Snowball method, [0,1,0,3,4] -> [1,0,0,3,4] -> [1,3,0,0,4] -> [1,3,4,0,0]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size(), zeroPos = 0;
        for (int i = 0; i < sz; i++) {
            if (nums[i] == 0 && nums[zeroPos] != 0) {
                zeroPos = i;
            }
            if (nums[i] != 0 && nums[zeroPos] == 0) {
                nums[zeroPos] = nums[i];
                nums[i] = 0;
                zeroPos++;
            }
        }
    }
};

// Another version, record snowball size, more concise
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size(), snowballSize = 0;
        for (int i = 0; i < sz; i++) {
            if (nums[i] == 0) snowballSize++;
            else if (snowballSize > 0) {
                nums[i - snowballSize] = nums[i];
                nums[i] = 0;
            }
        }
    }
};