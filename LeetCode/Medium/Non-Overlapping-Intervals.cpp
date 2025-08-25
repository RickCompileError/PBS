// O(nlogn), there is an sort by start version
struct {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
} cmp;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int non = 0;
        int cur = 0;
        int sz = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < sz; i++) {
            if (intervals[cur][1] > intervals[i][0]) {
                non++;
                continue;
            }
            cur = i;
        }

        return non;
    }
};
