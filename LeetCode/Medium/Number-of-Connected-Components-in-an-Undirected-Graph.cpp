// Time: O(V+E), Space: O(V+E)
class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        if (visited[node]) {
            return;
        }

        visited[node] = true;
        for (auto& i: graph[node]) {
            dfs(graph, visited, i);
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int treeAmount = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            treeAmount++;
            dfs(graph, visited, i);
        }

        return treeAmount;
    }
};

// DSU version, Time: O(V + (E*a(V))), Space: O(V), a() is used for amortized complexity
class DSU {
private:
    vector<int> parents;
    vector<int> ranks;

public:
    DSU(int n) {
        parents.resize(n);
        ranks.resize(n, 1);
        for (int i = 0; i < n; i++) {
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
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        int roots = n;
        for (auto& edge: edges) {
            if (merge(edge[0], edge[1])) {
                roots--;
            }
        }

        return roots;
    }
};

