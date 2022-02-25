#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n, ans = 0;
    cin >>n;
    ll a[n+1]{0}; // range 1 ~ n
    for (int i=1;i<=n;i++) cin >>a[i];
    map<ll,ll> appear;
    for (int i=1;i<=n;i++){
        a[i] = a[i]%n+n; // avoid negative number problem, if n = 5 => -1 === 4
        a[i] = (a[i] + a[i-1]) % n;
        // check itself and it remainder, (a[i2] - a[i1]) % n = 0 => (a[i2] % n) = (a[i1] % n)
        ans += (a[i]%n==0) + appear[a[i]]++;
    }
    cout <<ans <<endl;
}