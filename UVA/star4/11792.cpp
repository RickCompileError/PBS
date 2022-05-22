// using bfs
// the code can easily time out, don't know why :) 🖕
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

const int mxN = 1e4+5;
vector<int> station[mxN];
vector<int> important;
int station_count[mxN]{0};
int dist[mxN]{0};
bool visited[mxN]{0};

int main(){
    int cs, N, S, prev, cur;
    cin >>cs;
    while (cs--){
        cin >>N >>S;
        for (int i=1;i<=N;i++) station[i].clear();
        important.clear();
        memset(station_count,0,sizeof(station_count));
        while (S--){
            prev = -1;
            while (cin >>cur && cur){
                station_count[cur]++;
                if (prev>0) station[cur].push_back(prev), station[prev].push_back(cur);
                prev = cur;
            }
        }
        for (int i=1;i<=N;i++)
            if (station_count[i]>1) important.push_back(i);
        int mnp = -1, mnd = -1;
        for (int i: important){
            memset(dist,0x3f,sizeof(dist));
            memset(visited,0,sizeof(visited));
            queue<int> q({i});
            dist[i] = 0;
            while (!q.empty()){
                int node = q.front();
                q.pop();
                visited[node] = true;
                for (int j: station[node]){
                    if (dist[j]>dist[node]+1){
                        dist[j] = dist[node]+1;
                        if (!visited[j]){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
            int sum = 0;
            for (int j: important) sum += dist[j];
            if (mnp==-1 || sum<mnd){
                mnp = i;
                mnd = sum;
            }
        }
        cout <<"Krochanska is in: " <<mnp <<endl;
    }
}