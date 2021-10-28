#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll f(ll n){
    ll sum = 0;
    while (n>0) sum += n%10, n /= 10;
    return sum;
}

ll g(ll n){
    ll ans = n;
    while (ans>=10) ans = f(ans);
    return ans;
}

int main(){
    ll n;
    while (cin >>n && n!=0) cout <<g(n) <<endl;
}