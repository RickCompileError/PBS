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
bool init[mxN];
bool goal[mxN];
int ans{0};
vector<int> pick;

void dfs(int cur=1, int prev=-1, bool isOdd=true, bool oflip=false, bool eflip=false){
    init[cur] ^= (isOdd?oflip:eflip);
    if (init[cur]!=goal[cur]){
        ans++;
        pick.pb(cur);
        if (isOdd) oflip = !oflip;
        else eflip = !eflip;
    }
    for (int i: g[cur]){
        if (i==prev) continue;
        dfs(i, cur, !isOdd, oflip, eflip);
    }
}

void solve(){
    int n, u, v;
    cin >>n;
    for (int i=1;i<n;i++) cin >>u >>v, g[u].pb(v), g[v].pb(u);
    for (int i=1;i<=n;i++) cin >>init[i];
    for (int i=1;i<=n;i++) cin >>goal[i];
    dfs();
    cout <<ans <<endl;
    for (int i: pick) cout <<i <<endl;
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}