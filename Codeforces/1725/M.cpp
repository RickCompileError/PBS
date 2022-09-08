#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define e1 first
#define e2 second
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back

using namespace std;

int n, m;
const int mxN=1e5+5, mxM=2e5+5;
const ll INFF = 1e16;
vector<pli> from[mxN*2];
vector<ll> ans(mxN*2, INFF);
bool visited[mxN*2]{0};

void solve(){
    cin >>n >>m;
    int u, v, w;
    for (int i=1;i<=n;i++) from[i].pb({0,n+i});
    for (int i=0;i<m;i++){
        cin >>u >>v >>w;
        from[u].pb({w,v});
        from[n+v].pb({w,n+u});
    }
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    ans[1] = 0;
    pq.push({0,1});
    while (!pq.empty()){
        int cur = pq.top().e2;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (pli i: from[cur]){
            ans[i.e2] = min(ans[i.e2], ans[cur]+i.e1);
            pq.push({ans[i.e2], i.e2});
        }
    }
    for (int i=n+2;i<=2*n;i++) cout <<(ans[i]==INFF?-1:ans[i]) <<' ';
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}