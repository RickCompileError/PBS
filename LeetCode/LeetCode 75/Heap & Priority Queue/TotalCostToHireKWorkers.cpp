// Time: O(nlogn), Space: O(n)
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int l = 0, r = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> firstC, lastC;
        while (l < candidates) firstC.push(costs[l++]);
        while (l <= r && candidates--) lastC.push(costs[r--]);
        long long ans = 0;
        while (k--) {
            if (firstC.empty()) {
                ans += lastC.top();
                lastC.pop();
                continue;
            }
            if (lastC.empty()) {
                ans += firstC.top();
                firstC.pop();
                continue;
            }
            if (firstC.top() <= lastC.top()) {
                ans += firstC.top();
                firstC.pop();
                if (l <= r) firstC.push(costs[l++]);
            } else {
                ans += lastC.top();
                lastC.pop();
                if (l <= r) lastC.push(costs[r--]);
            }
        }
        return ans;
    }
};

// More readable
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int l = 0, r = costs.size() - 1, vall, valr;
        priority_queue<int, vector<int>, greater<int>> pql, pqr;
        long long ans = 0;

        while (k--) {
            while (pql.size() < candidates && l <= r) pql.push(costs[l++]);
            while (pqr.size() < candidates && l <= r) pqr.push(costs[r--]);
            vall = pql.size() ? pql.top() : INT_MAX;
            valr = pqr.size() ? pqr.top() : INT_MAX;
            if (vall <= valr) {
                pql.pop();
                ans += vall;
            } else {
                pqr.pop();
                ans += valr;
            }
        }
        return ans;
    }
};