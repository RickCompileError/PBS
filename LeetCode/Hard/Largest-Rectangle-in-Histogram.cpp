// O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        long long ans = 0;
        int sz = heights.size();

        s.push(-1);

        for (int i = 0; i < sz; i++) {
            while (s.top() != -1 && heights[s.top()] > heights[i]) {
                long long height = heights[s.top()]; s.pop();
                ans = max(ans, height * (i - s.top() - 1));
            }
            s.push(i);
        }

        while (s.top() != -1) {
            long long height = heights[s.top()]; s.pop();
            ans = max(ans, height * (sz - s.top() - 1));
        }

        return ans;
    }
};
