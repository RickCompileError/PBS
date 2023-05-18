#include <bits/stdc++.h>

#define pb push_back
#define ll long long

using namespace std;

int main(){
    int T;
    cin >>T;
    while (T--){
        vector<ll> v;
        int l;
        while (cin >>l && l) v.pb(l);
        sort(v.begin(), v.end(), greater<ll>());
        ll ans = 0;
        for (int i=1;i<=v.size() && ans<=5000000;i++) ans += 2*pow(v[i-1], i);
        if (ans<=5000000) cout <<ans <<endl;
        else cout <<"Too expensive\n";
    }
}