// Time: O(E*a(V)), Space: O(V)
class DSU {
private:
    vector<int> parents;
    vector<int> ranks;

public:
    DSU(int n) {
        parents.resize(n + 1);
        ranks.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parents[i] = i;
        }
    }

    int find(int n) {
        return n == parents[n] ? n : (parents[n] = find(parents[n]));
    }

    bool merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) {
            return false;
        }

        if (ranks[pb] > ranks[pa]) {
            swap(pa, pb);
        }
        parents[pb] = pa;
        ranks[pa] += ranks[pb];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        int sz = edges.size();
        int illegalEdge = -1;

        for (int i = 0; i < sz; i++) {
            if (!dsu.merge(edges[i][0], edges[i][1])) {
                illegalEdge = i;
            }
        }
        return edges[illegalEdge];
    }
};

// By using DFS, we need to record all the nodes when encounting cycle
// need one more variable to record the cycle starting node

// By using Topological Sort (Kahn's Algorithm), check if the indegree number is greater than 2
