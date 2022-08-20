#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define pll pair<ll,ll>
#define e1 first
#define e2 second
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back

using namespace std;

void solve(){
    ll n, k, b, s;
    cin >>n >>k >>b >>s;
    if (b*k>s){
        cout <<-1 <<endl;
        return;
    }
    vector<ll> v(n,0);
    v[0] = k*b, s -= k*b;
    for (int i=0;i<n && s>0;i++){
        v[i] += min(s, k-1);
        s -= min(s, k-1);
    }
    if (s>0){
        cout <<-1 <<endl;
        return;
    }
    for (ll i: v) cout <<i <<' ';
    cout <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}