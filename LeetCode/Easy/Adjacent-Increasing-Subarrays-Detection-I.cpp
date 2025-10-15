// Time: O(n), Space: O(n)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int counter = 0;
        int sz = nums.size();
        unordered_set<int> matchHead;

        for (int i = 0; i < sz; i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                counter++;
            } else {
                counter = 1;
            }
            if (counter >= k) {
                matchHead.insert(i - k + 1);
            }
        }

        for (auto& head: matchHead) {
            if (matchHead.find(head + k) != matchHead.end()) {
                return true;
            }
        }

        return false;
    }
};

// Time: O(kn), Space: O(1)
class Solution {
public:

bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) return false;
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2 * k) return false;

    for (int i = 0; i <= n - 2 * k; i++) {
        if (isStrictlyIncreasing(nums, i, k) && isStrictlyIncreasing(nums, i + k, k)) {
            return true;
        }
    }

    return false;
}
};
