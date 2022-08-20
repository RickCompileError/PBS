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
#define rep(i, l, r) for (int i=l;i<=r;i++)
#define repn(i, l, r) for (int i=l;i<r;i++)

using namespace std;

void solve(){
    int n, m, ind, x;
    cin >>n >>m;
    int v[n+2]{0};
    for (int i=1;i<=n;i++) cin >>v[i];
    ll cnt = 0, ans = 0;
    for (int i=1;i<=n;i++){
        cnt += (v[i]!=v[i-1]?i:1);
        ans += cnt;
    }
    while (m--){
        cin >>ind >>x;
        if (v[ind]==x){
            cout <<ans <<endl;
            continue;
        }
        if (ind>1 && (v[ind-1]==v[ind] || v[ind-1]==x)) ans += 1LL*(n-ind+1)*(ind-1)*(v[ind-1]==x?-1:1);
        if (ind<n && (v[ind+1]==v[ind] || v[ind+1]==x)) ans += 1LL*(n-ind)*(ind)*(v[ind+1]==x?-1:1);
        v[ind] = x;
        cout <<ans <<endl;
    }
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}