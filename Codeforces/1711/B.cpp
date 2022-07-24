#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

void solve(){
    int n, m, x, y; cin >>n >>m;
    int a[n]; for (int i=0;i<n;i++) cin >>a[i];
    vector<int> v[n];
    for (int i=0;i<m;i++){
        cin >>x >>y, x--, y--;
        v[x].push_back(y), v[y].push_back(x);
    }
    int ans = INF;
    for (int i=0;i<n;i++){
        if (v[i].size() & 1) ans = min(ans, a[i]);
        for (int j: v[i]) if ((v[i].size()+v[j].size()-1) & 1) ans = min(ans, a[i]+a[j]);
    }
    cout <<(m&1?ans:0) <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}