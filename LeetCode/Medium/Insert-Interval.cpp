// Time: O(n), Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> nIntervals;
        int sz = intervals.size();
        int idx = 0;

        while (idx < sz && intervals[idx][1] < newInterval[0]) {
            nIntervals.push_back(intervals[idx++]);
        }

        if (idx == sz) {
            nIntervals.push_back(newInterval);
            return nIntervals;
        }

        newInterval[0] = min(newInterval[0], intervals[idx][0]);
        
        while (idx < sz && intervals[idx][0] <= newInterval[1]) {
            newInterval[1] = max(newInterval[1], intervals[idx++][1]);
        }

        nIntervals.push_back(newInterval);
        
        while (idx < sz) {
            nIntervals.push_back(intervals[idx++]);
        }

        return nIntervals;
    }
};

// Linear Optimize
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> nIntervals;
        int sz = intervals.size();
        int idx = 0;

        while (idx < sz && intervals[idx][1] < newInterval[0]) {
            nIntervals.push_back(intervals[idx++]);
        }

        while (idx < sz && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }

        nIntervals.push_back(newInterval);

        while (idx < sz) {
            nIntervals.push_back(intervals[idx++]);
        }

        return nIntervals;
    }
};

// Can use Binary Search, find the interval which has the maximum right side value and lower than left side value of newInterval
// Insert newInterval back to that interval
// Than iterate the intervals to build the new intervals
// Time: O(n), Space: O(1)
