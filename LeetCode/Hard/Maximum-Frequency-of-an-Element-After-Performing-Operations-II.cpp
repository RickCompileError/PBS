// Time: O(nlogn), Space: O(n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        unordered_map<int,int> count;
        int ans = 0, sz = nums.size();
        int right = 0, left = 0;

        for (auto& num: nums) {
            while (right < sz && nums[right] <= num + k) {
                count[nums[right]]++;
                right++;
            }
            while (left < sz && nums[left] < num - k) {
                count[nums[left]]--;
                left++;
            }
            // we can add 0 to num, so the maximum freq can define as (right - left)
            ans = max(ans, min(right - left, count[num] + numOperations));
        }

        for (int i = 0, j = 0; j < sz; j++) {
            while ((long long)nums[i] + k + k < nums[j]) {
                i++;
            }
            ans = max(ans, min(j - i + 1, numOperations));
        }

        return ans;
    }
};
