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

