// Kruskal's Algorithm, PQ: O(ElogE), DSU: O(Ea(V)), Time: O(ElogE) or O(ElogV), Space: O(V^2)
// Because V - 1 <= E <= V^2, logE <= logV^2, so the time complexity can be O(ElogV)
class DSU {
private:
    vector<int> parents;
    vector<int> ranks;

public:
    DSU (int sz) {
        parents.resize(sz);
        ranks.resize(sz, 1);
        for (int i = 0; i < sz; i++) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int x = abs(points[i][0] - points[j][0]);
                int y = abs(points[i][1] - points[j][1]);
                pq.push({x + y, i, j});
            }
        }

        DSU dsu(sz);
        int cost = 0;

        while (!pq.empty()) {
            vector<int> dist = pq.top(); pq.pop();
            if (!dsu.merge(dist[1], dist[2])) {
                continue;
            }
            cost += dist[0];
        }

        return cost;
    }
};

// Kruskal's Sorting, Time: O(V^2logV), Space: O(V^2)
class DSU {
private:
    vector<int> parents;
    vector<int> ranks;

public:
    DSU (int sz) {
        parents.resize(sz);
        ranks.resize(sz, 1);
        for (int i = 0; i < sz; i++) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int x = abs(points[i][0] - points[j][0]);
                int y = abs(points[i][1] - points[j][1]);
                pq.push({x + y, i, j});
            }
        }

        DSU dsu(sz);
        int cost = 0;

        while (!pq.empty()) {
            vector<int> dist = pq.top(); pq.pop();
            if (!dsu.merge(dist[1], dist[2])) {
                continue;
            }
            cost += dist[0];
        }

        return cost;
    }
};

// Prim's Algorithm, Time: O(V^2), Space: O(V)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        vector<bool> visited(sz, false);
        vector<int> dist(sz, INT_MAX);
        int cost = 0;
        int node = 0;

        for (int i = 1; i < sz; i++) {
            visited[node] = true;
            int nxtNode = -1;
            for (int j = 0; j < sz; j++) {
                if (visited[j]) {
                    continue;
                }
                int x = abs(points[node][0] - points[j][0]);
                int y = abs(points[node][1] - points[j][1]);
                dist[j] = min(dist[j], x + y);
                if (nxtNode == -1 || dist[j] < dist[nxtNode]) {
                    nxtNode = j;
                }
            }
            cost += dist[nxtNode];
            node = nxtNode;
        }

        return cost;
    }
};
