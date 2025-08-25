// Time: O(nlogn), Space: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<vector<int>> v;

        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < sz; i++) {
            if (intervals[i - 1][1] < intervals[i][0]) {
                v.push_back(intervals[i - 1]);
            } else {
                intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
        }
        v.push_back(intervals[sz - 1]);

        return v;
    }
};

// Sweep Line Algorithm, Time: O(nlogn), Space: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int cumulativePoint = 0;
        vector<int> interval;
        vector<vector<int>> ans;
        map<int,int> m;


        for (auto& i: intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }

        for (auto& [val, amount]: m) {
            if (interval.empty()) {
                interval.push_back(val);
            }
            cumulativePoint += amount;
            if (cumulativePoint == 0) {
                interval.push_back(val);
                ans.push_back(interval);
                interval.clear();
            }
        }

        return ans;
    }
};

// Greedy, Trade-Off, Use Space safe Time, Time: O(n + m), Space: (m)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int mxStart = 0;

        for (auto& i: intervals) {
            mxStart = max(mxStart, i[0]);
        }

        vector<int> records(mxStart + 1, 0);
        
        for (auto& i: intervals) {
            // plus one to handle the possibility that end is 0
            records[i[0]] = max(records[i[0]], i[1] + 1);
        }

        int end = -1;
        vector<int> interval;
        vector<vector<int>> ans;

        for (int i = 0; i <= mxStart; i++) {
            if (records[i] > 0) {
                if (interval.empty()) {
                    interval.push_back(i);
                    interval.push_back(records[i] - 1);
                }
                interval[1] = max(interval[1], records[i] - 1);
            }

            if (!interval.empty() && i == interval[1]) {
                ans.push_back(interval);
                interval.clear();
            }
        }

        if (!interval.empty()) {
            ans.push_back(interval);
        }

        return ans;
    }
};
