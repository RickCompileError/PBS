/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// Time: O(nlogn), Space: O(n)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& i: intervals) {
            if (!pq.empty() && pq.top() <= i.start) {
                pq.pop();
            }
            pq.push(i.end);
        }

        return pq.size();
    }
};

// Sweap Line Algorithm, Time: O(nlogn), Space: O(n)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> m;
        for (auto& i: intervals) {
            m[i.start]++;
            m[i.end]--;
        }

        int interval = 0, day = 0;

        for (auto& [k, v]: m) {
            interval += v;
            day = max(day, interval);
        }

        return day;
    }
};

// Can use two pointers by saving the start and end time, Time: O(nlogn), Space: O(n)

// Can use greedy, like pointer but put start and end time together with {time, +-1} format
