// map, slow
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> record;
        int duplicate = 0, size = nums.size();
        long long ans = 0, sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            record[nums[i]]++;
            duplicate += (record[nums[i]] > 1);
        }
        if (!duplicate) ans = max(ans, sum);

        for (int i = k; i < size; i++) {
            sum += nums[i];
            duplicate += (++record[nums[i]] > 1);
            sum -= nums[i - k];
            duplicate -= (--record[nums[i - k]] > 0);
            if (!duplicate) ans = max(ans, sum);
        }

        return ans;
    }
};

// unordered_map, the fatest
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> element;
        int size = nums.size();
        long long ans = 0;
        long long sum = 0;
        int begin = 0;
        for (int end = 0; end < size; end++) {
            if (element.find(nums[end]) == element.end()) {
                sum += nums[end];
                element.insert(nums[end]);

                if (end - begin + 1 == k) {
                    ans = max(ans, sum);
                    sum -= nums[begin];
                    element.erase(nums[begin]);
                    begin++;
                }
            } else {
                while (nums[begin] != nums[end]) {
                    sum -= nums[begin];
                    element.erase(nums[begin]);
                    begin++;
                }
                begin++;
            }
        }

        return ans;
    }
};
