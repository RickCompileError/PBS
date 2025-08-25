// Time: O(nlogn), Space: O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sz = events.size();
        int day = 0, i = 0, attend = 0;

        sort(events.begin(), events.end());
        while (pq.size() || i < sz) {
            if (pq.size() == 0) {
                day = events[i][0];
            }

            while (i < sz && events[i][0] == day) {
                pq.push(events[i++][1]);
            }

            pq.pop();
            attend++, day++;

            while (pq.size() && pq.top() < day) {
                pq.pop();
            }
        }

        return attend;
    }
};
