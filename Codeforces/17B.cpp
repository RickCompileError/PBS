#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n; cin >>n;
    int m[n+1]; for (int i=1;i<=n;i++) cin >>m[i];
    int q, a, b, c; cin >>q;
    int s[n+1]{0};
    int cost[n+1]; memset(cost, 0x3f, sizeof(cost));
    for (int i=0;i<q;i++){
        cin >>a >>b >>c;
        if (m[a]<=m[b]) continue;
        if (cost[b]>c) cost[b] = c, s[b] = a;
    }
    int legal  = 0;
    ll ans = 0;
    for (int i=1;i<=n;i++){
        if (s[i]==0) legal++;
        else ans += cost[i];
    }
    cout <<(legal==1?ans:-1) <<endl;
}