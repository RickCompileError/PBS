// Time: O(m^2 + n^2), Space: O(m + n)
class Solution {
private:
    int path(unordered_map<int,vector<int>>& g, int node, int parent, int k) {
        if (k < 0) {
            return 0;
        }
        int way = 1;
        for (auto& i: g[node]) {
            if (i != parent) {
                way += path(g, i, node, k - 1);
            }
        }
        return way;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int sz1 = edges1.size(), sz2 = edges2.size();
        unordered_map<int,vector<int>> graph1, graph2;

        for (auto& e: edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e: edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        vector<int> ans(sz1 + 1, 0);

        int mxWay = -1;
        for (int j = 0; j <= sz2; j++) {
            mxWay = max(mxWay, path(graph2, j, -1, k - 1));
        }
        for (int i = 0; i <= sz1; i++) {
            ans[i] += path(graph1, i, -1, k) + mxWay;
        }

        return ans;
    }
};
