class Solution {
public:
    int findByBruteForce(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }

    int findByArray(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        for (auto i: nums) {
            if (v[i]) {
                return i;
            }
            v[i]++;
        }
        return -1;
    }

    int findByHash(vector<int>& nums) {
        set<int> s;
        for (auto i: nums) {
            if (s.find(i) != s.end()) {
                return i;
            }
            s.insert(i);
        }
        return -1;
    }

    int findByVisit(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            int idx = abs(nums[i]);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }
        return -1;
    }

    int findBySort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }

    int findByFloydCycle(vector<int>& nums) {
        int slow{0}, fast{0};
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    int findByBinarySearch(vector<int>& nums) {
        int sz = nums.size();
        int l = 1, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            int counter = 0;
            for (auto i: nums) {
                if (i <= m) {
                    counter++;
                }
            }

            if (counter <= m) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }

    int findDuplicate(vector<int>& nums) {
        return findByBinarySearch(nums);
    }
};
