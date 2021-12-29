#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define Node pair<int,int>

using namespace std;

const int mxN = 2e3, mxM = 1e4;
vector<int> city[mxN+1];
bool air[mxN+1];
int dis[mxN+1];
int n, m, k, a, q;
int city1, city2, des1, des2;

int main(){
    int X; cin >>X;
    for (int cs=1;cs<=X;cs++){
        printf("Case %d:\n",cs);
        cin >>n >>m >>k;
        for (int i=0;i<mxN+1;i++) city[i].clear(), air[i] = false;
        for (int i=0;i<k;i++) cin >>a, air[a] = true;
        for (int i=0;i<m;i++){
                cin >>city1 >>city2;
                city[city1].push_back(city2), city[city2].push_back(city1);
        }
        cin >>q;
        for (int i=0;i<q;i++){
            cin >>des1 >>des2;
            Node node;
            memset(dis,0x3f,sizeof(dis));
            dis[des1] = !air[des1];
            priority_queue<Node,vector<Node>,greater<Node>> pq;
            pq.push({des1,dis[des1]});
            while (!pq.empty()){
                node = pq.top(), pq.pop();
                if (node.second>dis[des2]) continue;
                for (int j: city[node.first]){
                    if (node.second+(!air[j])<dis[j]){
                        dis[j] = node.second+(!air[j]);
                        pq.push({j,dis[j]});
                    }
                }
            }
            if (des1==des2) cout <<0 <<endl;
            else if (dis[des2]==INF) cout <<-1 <<endl;
            else cout <<dis[des2] <<endl;
        }
        cout <<endl;
    }
}