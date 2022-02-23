#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int sz = 1e6;
vector<int> prime;

void build(){
    bool p[sz]{true,true};
    for (int i=2;i*i<sz;i++){
        if (p[i]) continue;
        for (int j=i*i;j<sz;j+=i) p[j] = true;
    }
    for (int i=2;i<sz;i++) if (!p[i]) prime.push_back(i);
}

int main(){
    build();
    ll n;
    while (cin >>n){
        if (n==0){
            cout <<1 <<endl;
            break;
        }
        map<int,int> factor;
        while (n%2==0) n /= 2;
        for (int i=0;i<prime.size() && n>1;i++){
            while (n%prime[i]==0){
                factor[prime[i]]++;
                n /= prime[i];
            }
        }
        if (n>1) factor[n]++;
        ll ans = 1;
        for (auto const& [k,v] : factor) ans *= (v+1);
        cout <<ans <<endl;
    }    
}