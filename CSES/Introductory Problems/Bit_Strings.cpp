#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll mod=1e9+7;

ll dp(int n){
    if (n==1) return 2;
    ll half = dp(n/2);
    return (n%2)?(2*half*half%mod):(half*half%mod);
}

int main(){
    int n;
    cin >>n;
    cout <<dp(n);
}