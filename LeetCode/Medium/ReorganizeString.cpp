// Time: O(nlogk), Space: O(n)
// k is the number of unique characters
// Counting the frequency of the characters and using priority queue to reorganize the string
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> um;
        for (char i: s) um[i]++;
        priority_queue<pair<int,char>> heap;
        for (auto &[k,v]: um) heap.push({v, k});
        string res = "";
        while (heap.size() >= 2) {
            auto [f1, c1] = heap.top(); heap.pop();
            auto [f2, c2] = heap.top(); heap.pop();
            res += c1;
            res += c2;
            if (--f1 > 0) heap.push({f1, c1});
            if (--f2 > 0) heap.push({f2, c2});
        }
        if (!heap.empty()) {
            auto [f, c] = heap.top();
            if (f > 1) return "";
            res += c;
        }
        return res;
    }
};

// Time: O(n + klogk), Space: O(n)
// n for counting frequency, and klogk for sorting the unique characters by their frequency
// Counting the frequency of the characters and using vector with sort by their frequency to reorganize the string
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> um;
        for (char i: s) um[i]++;
        vector<char> chars;
        for (auto &i: um) chars.emplace_back(i.first);
        sort(chars.begin(), chars.end(), [&](char a, char b) {
            return um[a] > um[b];
        });
        if (um[chars[0]] > (s.size() + 1) / 2) return "";
        int i = 0;
        for (char c: chars) {
            while (um[c]--) {
                if (i >= s.size()) i = 1;
                s[i] = c;
                i += 2;
            }
        }
        return s;
    }
};