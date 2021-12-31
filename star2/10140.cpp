#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll> prime;
vector<ll> p;

void build(){
    bool tmp[50001];
    tmp[0] = tmp[1] = true;
    for (ll i=2;i*i<=50000;i++){
        if (tmp[i]) continue;
        for (ll j=i*i;j<=50000;j+=i) tmp[j] = true;
    } 
    for (ll i=2;i<=50000;i++) if (!tmp[i]) prime.push_back(i);
}

bool is_prime(ll n){
    if (n==1) return false;
    for (ll i: prime){
        if (i==n) return true;
        if (n%i==0) return false;
    }
    return true;
}

int main(){
    build();
    ll l, u;
    while (cin >>l >>u){
        p.clear();
        if (l<=2) p.push_back(2);
        for (ll i=l+(l%2==0);i<=u;i+=2){
            if (is_prime(i)) p.push_back(i);
        }
        if (p.size()<=1) cout <<"There are no adjacent primes.\n";
        else{
            ll mn = 1, mx = 1;
            for (ll i=2;i<p.size();i++){
                if (p[i]-p[i-1]<p[mn]-p[mn-1]) mn = i;
                if (p[i]-p[i-1]>p[mx]-p[mx-1]) mx = i;
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",p[mn-1],p[mn],p[mx-1],p[mx]);
        }
    }
}