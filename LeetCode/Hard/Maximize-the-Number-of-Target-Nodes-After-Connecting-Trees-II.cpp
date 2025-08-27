// Time: O(M + N), Space: O(M + N)
#define TWOD unordered_map<int,vector<int>>
#define ONED vector<int>

class Solution {
private:
    void bipartite(TWOD& graph, int node, int parent, ONED& color, int& odd, int& even) {
        if (color[node] == 0) {
            even++;
        } else {
            odd++;
        }

        for (auto& sib: graph[node]) {
            if (sib != parent) {
                color[sib] = color[node] ^ 1;
                bipartite(graph, sib, node, color, odd, even);
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int sz1 = edges1.size(), sz2 = edges2.size();
        TWOD graph1, graph2;

        for (auto& e: edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e: edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        int odd1 = 0, even1 = 0, odd2 = 0, even2 = 0, mx2 = 0;
        ONED color1(sz1 + 1, -1), color2(sz2 + 1, -1), ans(sz1 + 1, 0);
        color1[0] = 0;
        color2[0] = 1;
        bipartite(graph1, 0, -1, color1, odd1, even1);
        bipartite(graph2, 0, -1, color2, odd2, even2);
        mx2 = max(odd2, even2);
        for (int i = 0; i <= sz1; i++) {
            ans[i] = (color1[i] ? odd1 : even1) + mx2;
        }

        return ans;
    }
};
