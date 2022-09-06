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

const int mxN = 2e5+5;
int v[mxN];

void solve(){
    ll N; cin >>N;
    if (N==1){
        cout <<3 <<endl;
        return;
    }
    N--;
    ll ans = 4+(N+2)/3*4;
    if (N%3==1) ans -= 3;
    if (N%3==2) ans -= 1;
    cout <<ans <<endl;
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}