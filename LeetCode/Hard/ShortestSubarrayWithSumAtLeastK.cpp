// solution 1: priority_queue
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX, size = nums.size();
        long long cumulativeSum = 0;
        priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<>> prefixSum;

        for (int i = 0; i < size; i++) {
            cumulativeSum += nums[i];

            if (cumulativeSum >= k) ans = min(ans, i + 1);

            while (!prefixSum.empty() && cumulativeSum - prefixSum.top().first >= k) {
                ans = min(ans, i - prefixSum.top().second);
                prefixSum.pop();
            }

            prefixSum.emplace(cumulativeSum, i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// solution 2: stack + binary search
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<pair<long long, int>> monotonicStack;
        monotonicStack.emplace_back(0, -1);

        long long cumulativeSum = 0;
        int ans = INT_MAX;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            cumulativeSum += nums[i];
            while (!monotonicStack.empty() && monotonicStack.back().first >= cumulativeSum) {
                monotonicStack.pop_back();
            }

            monotonicStack.emplace_back(cumulativeSum, i);

            int candidateIdx = findCandidateIdx(monotonicStack, cumulativeSum - k);

            if (candidateIdx != -1) {
                ans = min(ans, i - monotonicStack[candidateIdx].second);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

private:
    int findCandidateIdx(const vector<pair<long long, int>>& nums, long long bound) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m].first <= bound) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};

// deque
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<long long> cumulativeSums(size + 1, 0);

        for (int i = 1; i <= size; i++) {
            cumulativeSums[i] = nums[i - 1] + cumulativeSums[i - 1];
        }

        int ans = INT_MAX;
        deque<int> monotonic;

        for (int i = 0; i <= size; i++) {
            while (!monotonic.empty() && cumulativeSums[i] - cumulativeSums[monotonic.front()] >= k) {
                ans = min(ans, i - monotonic.front());
                monotonic.pop_front();
            }

            while (!monotonic.empty() && cumulativeSums[i] <= cumulativeSums[monotonic.back()]) {
                monotonic.pop_back();
            }

            monotonic.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

