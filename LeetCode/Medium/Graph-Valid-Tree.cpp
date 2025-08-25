// Time: O(V+E), Space: O(V+E)
class Solution {
private:
    bool isCycle(vector<vector<int>>& graph, unordered_set<int>& visited, int node, int parent) {
        if (visited.find(node) != visited.end()) {
            return true;
        }

        visited.insert(node);
        for (auto& i: graph[node]) {
            if (i == parent) {
                continue;
            }
            if (isCycle(graph, visited, i, node)) {
                return true;
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_set<int> visited;

        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        
        if (isCycle(graph, visited, 0, -1)) {
            return false;
        }

        return visited.size() == n;
    }
};

