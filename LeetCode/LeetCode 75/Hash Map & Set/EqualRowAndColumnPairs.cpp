// Time: O(n^2), Space: O(n^2)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int ans = 0;
        for (vector<int> i: grid) m[i]++;
        for (int i = 0, sz = grid.size(); i < sz; i++) {
            vector<int> v;
            for (int j = 0; j < sz; j++) v.emplace_back(grid[j][i]);
            ans += m[v];
        }
        return ans;
    }
};
// Another version is only use vector,
// extract all the column and put them into another vector,
// after it, loop through the vector and compare them.