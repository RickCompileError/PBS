// O(nlogn), unordered_map O(1), set insert and erase are about O(nlogn)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        set<int, greater<int>> s;
        vector<int> ans;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            int in = nums[i];
            um[in]++;
            s.insert(in);
            if (i >= k) {
                int out = nums[i - k];
                um[out]--;
                if (um[out] == 0) {
                    s.erase(out);
                }
            }
            if (i + 1 >= k) ans.push_back(*s.begin());
        }

        return ans;
    }
};

// O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            while (!d.empty() && d.back() < nums[i]) d.pop_back();
            d.push_back(nums[i]);
            if (i >= k && d.front() == nums[i - k]) d.pop_front();
            if (i + 1 >= k) ans.push_back(d.front());
        }

        return ans;
    }
};
