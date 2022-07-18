#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int n, c; cin >>n;
    map<int,vector<int>> m;
    for (int i=0;i<n;i++) cin >>c, m[c].push_back(i);
    for (int i=1;i<=n;i++){
        int ans = 1, prev = 0;
        for (int j=0,sz=m[i].size();j<sz;j++)
            if ((m[i][j]-m[i][prev])%2) ans++, prev = j;
        cout <<(m[i].size()?ans:0) <<' ';
    }
    cout <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}