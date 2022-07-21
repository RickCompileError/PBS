#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int n, m, s, j; cin >>n >>m;
    ll a[n+1]{0}; for (int i=1;i<=n;i++) cin >>a[i];
    ll ltor[n+1]{0}; for (int i=2;i<=n;i++) ltor[i] += ltor[i-1] + max(a[i-1]-a[i], (ll)0);
    ll rtol[n+1]{0}; for (int i=n-1;i>=1;i--) rtol[i] += rtol[i+1] + max(a[i+1]-a[i], (ll)0);
    while (m--){
        cin >>s >>j;
        cout <<(s<j?ltor[j]-ltor[s]:rtol[j]-rtol[s]) <<endl;
    }
}

int main(){
    int t = 1;
    while (t--) solve();
}