#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9+7;

ll binaryExponentiation(int base, int exponent){
    if (!exponent) return 1;
    ll result = binaryExponentiation(base, exponent/2);
    if (exponent%2) return (result*result%mod)*base%mod;
    else return result*result%mod;
}

int main(){
    ll n, s;
    cin >>n;
    s = n*(n+1)/2;
    if (s%2){
        cout <<0;
        return 0;
    }
    ll dp[s+1]{};
    dp[0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=i*(i+1)/2;j>=i;j--){
            dp[j] = (dp[j]+dp[j-i])%mod;
        }
    }
    // (a%mod)/(b%mod) != (a/b)%mod
    // it can't just doing mod, so we need to find modular inverse of denominator
    cout <<dp[s/2]*binaryExponentiation(2,mod-2)%mod <<endl;
}