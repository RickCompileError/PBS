// DFS, Time: O(V+E), Space: O(V+E), v is number of class, e is number of prerequisites
class Solution {
private:
    bool isIllegal(vector<vector<int>>& courseMap, vector<bool>& visited, int course) {
        if (visited[course]) {
            return true;
        }

        visited[course] = true;
        for (auto& c: courseMap[course]) {
            if (isIllegal(courseMap, visited, c)) {
                return true;
            }
        }
	// Early delete if no cycle exist to avoid duplicate check
        courseMap[course].clear();
        visited[course] = false;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courseMap(numCourses);

        for (auto& prerequisite: prerequisites) {
            courseMap[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<bool> visited(numCourses, false);
        for (int course = 0; course < numCourses; course++) {
            if (isIllegal(courseMap, visited, course)) {
                return false;
            }
        }

        return true;
    }
};

// Kahn's Algorithm, Time: O(V+E), Space: O(V+E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while (!roots.empty()) {
            handle++;
            int root = roots.front(); roots.pop();

            for (auto& i: courseMap[root]) {
                parentAmount[i]--;
                if (parentAmount[i] == 0) {
                    roots.push(i);
                }
            }

            courseMap[root].clear();
        }

        return handle == numCourses;
    }
};
