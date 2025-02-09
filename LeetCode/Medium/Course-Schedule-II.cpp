// Kahn's Algorithm (Topological Sort), Time: O(V+E), Space: O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courseMap(numCourses);
        vector<int> parentAmount(numCourses, 0);

        for (auto& prerequisite: prerequisites) {
            courseMap[prerequisite[1]].push_back(prerequisite[0]);
            parentAmount[prerequisite[0]]++;
        }

        queue<int> roots;
        for (int i = 0; i < numCourses; i++) {
            if (parentAmount[i] == 0) {
                roots.push(i);
            }
        }

        int handle = 0;
        vector<int> order;
        while (!roots.empty()) {
            int root = roots.front(); roots.pop();
            handle++;
            order.push_back(root);

            for (auto& i: courseMap[root]) {
                parentAmount[i]--;
                if (parentAmount[i] == 0) {
                    roots.push(i);
                }
            }

            courseMap[root].clear();
        }

        return handle == numCourses ? order : vector<int>();
    }
};

// We still can use DFS, but we still need to start from the node that has no "IN" edge
// And do the same check in DFS recursive function
