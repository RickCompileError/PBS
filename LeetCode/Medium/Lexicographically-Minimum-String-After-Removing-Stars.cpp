// Time: O(nlogn), Space: O(n)
class CMP {
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

class Solution {
public:
    string clearStars(string s) {
        int sz = s.size();
        vector<int> skipList;
        priority_queue<pair<int,int>, vector<pair<int,int>>, CMP> pq;

        for (int i = 0; i < sz; i++) {
            if (s[i] == '*') {
                if (pq.size()) {
                    skipList.push_back(pq.top().second);
                    pq.pop();
                }
                skipList.push_back(i);
                continue;
            }
            pq.push({s[i], i});
        }
        sort(skipList.begin(), skipList.end());

        int pos = 0;
        string ans = "";
        for (auto& skip: skipList) {
            while (pos < skip) {
                ans += s[pos++];
            }
            pos++;
        }
        while (pos < sz) {
            ans += s[pos++];
        }

        return ans;
    }
};

// Simplify
class CMP {
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

class Solution {
public:
    string clearStars(string s) {
        int sz = s.size();
        vector<bool> isRemoved(sz, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, CMP> pq;

        for (int i = 0; i < sz; i++) {
            if (s[i] == '*') {
                isRemoved[i] = true;
                if (pq.size()) {
                    isRemoved[pq.top().second] = true;
                    pq.pop();
                }
                continue;
            }
            pq.push({s[i], i});
        }

        string ans = "";
        for (int i = 0; i < sz; i++) {
            if (!isRemoved[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};
