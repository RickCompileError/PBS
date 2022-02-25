#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n, x, ans = 0;
    cin >>n >>x;
    ll a[n+1]{0};
    for (int i=1;i<=n;i++) cin >>a[i];
    map<ll,ll> appear;
    appear[0] = 1;
    for (int i=1;i<=n;i++){
        a[i] += a[i-1];
        if (appear[a[i]-x]) ans += appear[a[i]-x]; // x = a[i2] - a[i1]; i2 > i1;
        appear[a[i]]++;
    }
    cout <<ans <<endl;
}