// Time O(n), Space O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum = numbers[l] + numbers[r];

        while (sum != target) {
            if (sum < target) {
                sum -= numbers[l++];
                sum += numbers[l];
            } else {
                sum -= numbers[r--];
                sum += numbers[r];
            }
        }

        return vector<int>{l + 1, r + 1};
    }
};
