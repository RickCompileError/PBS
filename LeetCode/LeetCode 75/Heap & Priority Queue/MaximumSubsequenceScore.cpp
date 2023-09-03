// Time: O(nlogn), Space: O(n)
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz = nums1.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < sz; i++) v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end(), greater());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        for (auto& [key,value]: v) {
            pq.emplace(value);
            sum += value;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, sum * key);
            }
        }
        return ans;
    }
};