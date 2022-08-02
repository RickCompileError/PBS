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

bool d[10]{0};
int n;
ll ans = LLONG_MAX;

void dfs(ll l=0, int sum=0){
    if (sum>=n){
        if (sum==n) ans = min(ans,l);
        return;
    }
    for (int i=1;i<=9;i++){
        if (d[i]) continue;
        d[i] = true;
        dfs(l*10+i, sum+i);
        d[i] = false;
    }
}

void solve(){
    ans = LLONG_MAX;
    cin >>n;
    dfs();
    cout <<ans <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}