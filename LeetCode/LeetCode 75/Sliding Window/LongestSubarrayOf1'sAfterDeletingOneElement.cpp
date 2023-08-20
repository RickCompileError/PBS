/* 
 * Time: O(n), Memory: O(1)
 * The logic is same as MaxConsecutiveOnesII.cpp
 * You can thought that the program can flip 0 once to get the longest all 1's subarray
 * and after get the answer don't forget to minus one (because it is delete 0 actually!)
 * The sliding window doesn't shrink
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, sz = nums.size(), remove = 1;
        for (; j < sz; j++) {
            if (nums[j] == 0) remove--;
            if (remove < 0 && nums[i++] == 0) remove++;
        }
        return j - i - 1;
    }
};