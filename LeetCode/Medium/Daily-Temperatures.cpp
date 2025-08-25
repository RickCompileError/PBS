// Back to Front
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector<int> ans(sz, 0);
        stack<int> tempOrderIdx;

        for (int i = sz - 1; i >= 0; i--) {
            int waitDay = 0;
            while (!tempOrderIdx.empty() && temperatures[tempOrderIdx.top()] <= temperatures[i]) {
                waitDay += ans[tempOrderIdx.top()];
                tempOrderIdx.pop();
            }

            ans[i] = tempOrderIdx.empty() ? 0 : waitDay + 1;
            tempOrderIdx.push(i);
        }

        return ans;
    }
};

// Front to Back
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        stack<int> day;
        vector<int> waitDay(sz, 0);

        for (int i = 0; i < sz; i++) {
            while (!day.empty() && temperatures[day.top()] < temperatures[i]) {
                int d = day.top(); day.pop();
                waitDay[d] = i - d;
            }
            day.push(i);
        }

        return waitDay;
    }
};
