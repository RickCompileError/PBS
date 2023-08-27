// Time: O(n ^ 2), Space: O(n)
// BFS approach
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[1001]{0};
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int number = q.front();
            q.pop();
            visited[number] = true;
            for (int i: rooms[number]) if (!visited[i]) q.push(i);
        }
        for (int i = 0, sz = rooms.size(); i < sz; i++) if (!visited[i]) return false;
        return true;
    }
};
// DFS approach
class Solution {
public:

    void visitRoom(vector<vector<int>>& rooms, set<int>& visited, int key) {
        if (visited.find(key) != visited.end()) return;
        visited.insert(key);
        for (int k: rooms[key]) visitRoom(rooms, visited, k);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        visitRoom(rooms, visited, 0);
        return visited.size() == rooms.size();
    }
};