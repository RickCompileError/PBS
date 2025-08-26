// Time: O(nlogn), Space: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int counter = 0;
        int gsz = g.size(), ssz = s.size();
        int gidx = 0, sidx = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (gidx < gsz && sidx < ssz) {
            if (g[gidx] <= s[sidx]) {
                counter++;
                gidx++;
            }
            sidx++;
        }

        return counter;
    }
};
