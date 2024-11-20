// O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> u;
        for (auto c: s) u[c]++;

        for (auto c: t) u[c]--;

        for (auto c: u) if (c.second) return false;

        return true;
    }
};
