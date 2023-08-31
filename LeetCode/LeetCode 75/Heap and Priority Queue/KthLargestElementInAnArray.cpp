// Time: O(nlogn), Space: O(1)
// sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Time: O(nlogk), Space: O(k)
// heap, priority_queue, heap operations take O(logk) time
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
        for (int i = k, sz = nums.size(); i < sz; i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

// Time: Best or Avg = O(n), Worst = O(n^2), Space: O(1)
// quick select algorithm, using quicksort
// time limit exceeded
class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pivot_index) {
        int pivot_point = nums[pivot_index];
        swap(nums[pivot_index], nums[right]);
        int stored_index = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot_point) swap(nums[i], nums[stored_index++]);
        }
        swap(nums[stored_index], nums[right]);
        return stored_index;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pivot_index = rand() % (right - left + 1) + left;
            int new_pivot_index = partition(nums, left, right, pivot_index);
            if (new_pivot_index == nums.size() - k) return nums[new_pivot_index];
            else if (new_pivot_index > nums.size() - k) right = new_pivot_index - 1;
            else left = new_pivot_index + 1;
        }
    }
};