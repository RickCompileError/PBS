// Bellman Ford, Time: O(n + (m * k)), Space: O(n), n = # of cities, m = # of flights, k = # of stops
#define INF 0x3f3f3f3f

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> shortest_path(n, INF);
        shortest_path[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmp_shortest_path = shortest_path;

            for (auto& flight: flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];

                if (shortest_path[from] == INF) {
                    continue;
                }

                if (shortest_path[from] + cost < tmp_shortest_path[to]) {
                    tmp_shortest_path[to] = shortest_path[from] + cost;
                }
            }

            shortest_path = tmp_shortest_path;
        }

        return shortest_path[dst] == INF ? -1 : shortest_path[dst];
    }
};

// Shortest Path Faster, Time: O(n * k), Space: O(n + m)
#define INF 0x3f3f3f3f
#define PQ priority_queue

typedef struct {
    int to;
    int cost;
} Flight;

typedef struct {
    int to;
    int cost;
    int stop;
} Edge;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> shortest_path(n, INF);
        vector<vector<Flight>> adjacent(n, vector<Flight>());
        queue<Edge> pq;

        shortest_path[src] = 0;
        for (auto& flight: flights) {
            adjacent[flight[0]].push_back({flight[1], flight[2]});
        }
        pq.push({src, 0, 0});

        while (!pq.empty()) {
            Edge shortest = pq.front(); pq.pop();
            if (shortest.stop > k) {
                continue;
            }

            for (const auto& flight: adjacent[shortest.to]) {
                int nextCost = shortest.cost + flight.cost;
                if (nextCost < shortest_path[flight.to]) {
                    shortest_path[flight.to] = nextCost;
                    pq.push({flight.to, nextCost, shortest.stop + 1});
                }
            }
        }

        return shortest_path[dst] == INF ? -1 : shortest_path[dst];
    }
};
