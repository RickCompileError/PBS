#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define pll pair<ll,ll>
#define e1 first
#define e2 second
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back

using namespace std;

const int mxN = 1e5+5;
vector<int> g[mxN];

int getLeaf(int cur, int prev){
    if (g[cur].size()==1) return cur;
    for (int i: g[cur]){
        if (i==prev) continue;
        return getLeaf(i, cur);
    }
    return -1;
}

void solve(){
    int n, u, v;
    cin >>n;
    for (int i=1;i<n;i++) cin >>u >>v, g[u].pb(v), g[v].pb(u);
    int check = 0, root = -1;
    for (int i=1;i<=n;i++){
        if (g[i].size()>=3) check++;
        if (root==-1 || g[i].size()>g[root].size()) root = i;
    }
    if (check>1){
        cout <<"No" <<endl;
        return;
    }
    cout <<"Yes" <<endl <<g[root].size() <<endl;
    for (int i: g[root]){
        cout <<root <<' ' <<getLeaf(i, root) <<endl;
    }
}

void solve2(){
    int n, u, v, root{0};
    cin >>n;
    int deg[n+1]{0};
    for (int i=1;i<n;i++) cin >>u >>v, deg[u]++, deg[v]++;
    for (int i=1;i<=n;i++){
        if (deg[i]>2){
            if (root){
                cout <<"No" <<endl;
                return;
            }
            root = i;
        }
    }
    if (!root) root = 1;
    cout <<"Yes" <<endl <<deg[root] <<endl;
    for (int i=1;i<=n;i++){
        if (i==root || deg[i]!=1) continue;
        cout <<root <<' ' <<i <<endl;
    }
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve2();
}