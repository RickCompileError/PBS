// Time: O(nlogn), Space: O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> s;
        for (int i: arr) m[i]++;
        for (auto const& [key, val]: m) s.emplace(val);
        return m.size() == s.size();
    }
};