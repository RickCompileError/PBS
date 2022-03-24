#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll mod = 1e9+7;

ll exp(ll a, ll b){
    if (b==0) return 1;
    if (b==1) return a;
    return (b%2)?a*exp(a*a%mod,b/2)%mod:exp(a*a%mod,b/2);
}

ll exp2(ll a, ll b){
    if (b==0) return 1;
    ll tmp = exp2(a,b/2);
    return (b%2)?a*tmp%mod*tmp%mod:tmp*tmp%mod;
}

int main(){
    ll n, a, b;
    cin >>n;
    while (n--){
        cin >>a >>b;
        cout <<exp2(a,b) <<endl;
    }
}