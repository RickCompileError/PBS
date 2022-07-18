#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int n; cin >>n;
    ll h[n]; for (int i=0;i<n;i++) cin >>h[i];
    ll ans = 0;
    if (n%2){
        for (int i=1;i<n;i+=2) ans += max((ll)0,max(h[i-1],h[i+1])+1-h[i]);
    }else{
        int sz = n-1;
        ll a[sz]{INT_MAX};
        for (int i=1;i<sz;i++) a[i] = max((ll)0,max(h[i-1],h[i+1])+1-h[i]);
        for (int i=3;i<sz;i++){
            if (i%2) a[i] += a[i-2];
            else a[i] += min(a[i-3], a[i-2]);
        }
        ans = min(a[sz-2], a[sz-1]);
    }
    cout <<ans <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}