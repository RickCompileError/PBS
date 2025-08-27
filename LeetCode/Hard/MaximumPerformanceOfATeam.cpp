// Time: O(nlogn), Space: O(n)
const int mod = 1e9 + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) v.push_back({efficiency[i], speed[i]});
        sort(v.begin(), v.end(), greater());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        for (auto& [key, value]: v) {
            pq.emplace(value);
            sum += value;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * key);
        }
        return ans % mod;
    }
};