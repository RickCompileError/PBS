// Time: O(nlogn), Space: O(n)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<pair<int,int>> kv;

        for (int i = 0; i < sz; i++) {
            kv.push_back({nums[i], i});
        }
        sort(kv.begin(), kv.end(), [](auto& a, auto& b) { return a.first > b.first; });
        while (kv.size() > k) {
            kv.pop_back();
        }
        sort(kv.begin(), kv.end(), [](auto& a, auto& b) { return a.second < b.second; });

        vector<int> ans;
        for (auto& v: kv) {
            ans.push_back(v.first);
        }

        return ans;
    }
};

// Time: O(nk), Space: O(1)
// put first k and loop through the remaining elements keep finding minimum and remove
