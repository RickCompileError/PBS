// Bellman Ford Algorithm, Time: O(VE), Space: O(V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            for (const auto& time: times) {
                int u = time[0] - 1, v = time[1] - 1, w = time[2];
                if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }

        int mxDis = *max_element(dis.begin(), dis.end());
        return mxDis == INT_MAX ? -1 : mxDis;
    }
};

// Dijkstra's Algorithm, Time: O(ElogV), Space: O(V+E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> paths(n + 1);
        for (auto& time: times) {
            paths[time[0]].emplace_back(time[2], time[1]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> s;
        int t = 0;

        pq.emplace(0, k);

        while (!pq.empty()) {
            pair<int,int> edge = pq.top(); pq.pop();
            int w = edge.first, v = edge.second;

            if (s.count(v) != 0) {
                continue;
            }
            s.insert(v);
            t = w;

            for (auto& path: paths[v]) {
                int nxW = path.first, nxV = path.second;
                if (s.count(nxV) == 0) {
                    pq.emplace(w + nxW, nxV);
                }
            }
        }

        return s.size() == n ? t : -1;
    }
};

// Floyd Warshell Algorithm, Time: O(V^3), Space: O(V^2)
#define INF 0x3f3f3f3f
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto& time: times) {
            dist[time[0] - 1][time[1] - 1] = time[2];
        }

        for (int mid = 0; mid < n; mid++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);

        int mxDis = *max_element(dist[k - 1].begin(), dist[k - 1].end());
        return mxDis == INF ? -1 : mxDis;
    }
};

// Shortest Path Faster Algorithm, SPFA, Average Time: O(V+E), Worst Time: O(VE), Space: O(V+E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto& time: times) {
            graph[time[0]].emplace_back(time[1], time[2]);
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        queue<pair<int,int>> q;
        q.emplace(k, 0);

        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();
            if (dist[u] < t) {
                continue;
            }
            for (auto& [v, w]: graph[u]) {
                if (t + w < dist[v]) {
                    dist[v] = t + w;
                    q.emplace(v, t + w);
                }
            }
        }

        int mxTime = *max_element(dist.begin() + 1, dist.end());
        return mxTime == INT_MAX ? -1 : mxTime;
    }
};

// Can use DFS, Time: O(VE), Space: O(V + e)
