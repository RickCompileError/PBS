// Time: O(V+E), Space: O(V+E)
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int sz = colors.size();
        int visited = 0;
        int ans = -1;
        unordered_map<int, vector<int>> G;
        vector<int> in(sz, 0);
        vector<vector<int>> counter(sz, vector<int>(26, 0));
        queue<int> roots;

        for(auto& e: edges) {
            G[e[0]].push_back(e[1]);
            in[e[1]]++;
        }

        for (int i = 0; i < sz; i++) {
            if (in[i] == 0) {
                roots.push(i);
                counter[i][colors[i] - 'a'] = 1;
            }
        }

        while (roots.size()) {
            int root = roots.front(); roots.pop();
            int val = *max_element(counter[root].begin(), counter[root].end());
            ans = max(ans, val);
            visited++;
            for (int v: G[root]) {
                for (int i = 0; i < 26; i++) {
                    counter[v][i] = max(counter[v][i], counter[root][i] + (i == colors[v] - 'a'));
                }
                if (--in[v] == 0) {
                    roots.push(v);
                }
            }
        }

        return visited < sz ? -1 : ans;
    }
};
