// Interval, Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sz = s.size();
        vector<pair<int,int>> range(26, {-1,-1});

        for (int i = 0; i < sz; i++) {
            if (range[s[i] - 'a'].first == -1) {
                range[s[i] - 'a'] = {i, i};
            }
            range[s[i] - 'a'].second = i;
        }
        sort(range.begin(), range.end());

        int idx = 0;

        while (range[idx].first == -1) {
            idx++;
        }

        int rangeEnd = range[idx++].second;
        int prevEnd = -1;
        vector<int> partition;

        while (idx < 26) {
            if (range[idx].first > rangeEnd) {
                partition.push_back(rangeEnd - prevEnd);
                prevEnd = rangeEnd;
            }
            rangeEnd = max(rangeEnd, range[idx].second);
            idx++;
        }
        partition.push_back(rangeEnd - prevEnd);

        return partition;
    }
};

// Two Pointers, Time: O(n), Space: O(m), n = string length, m = appear char
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sz = s.size();
        unordered_map<char,int> lastAppear;

        for (int i = 0; i < sz; i++) {
            lastAppear[s[i]] = i;
        }

        vector<int> partition;
        int currEnd = 0;
        int prevEnd = -1;

        for (int i = 0; i < sz; i++) {
            currEnd = max(currEnd, lastAppear[s[i]]);

            if (i == currEnd) {
                partition.push_back(currEnd - prevEnd);
                prevEnd = currEnd;
            }
        }

        return partition;
    }
};
