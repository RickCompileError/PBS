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
    ll n, k;
    cin >>n >>k;
    if (((k&1)==0 && (k/2&1)==0)){
        cout <<"NO" <<endl;
        return;
    }
    cout <<"YES" <<endl;
    for (int i=4;i<=n;i+=4) cout <<i-1 <<' ' <<i <<endl;
    for (int i=2;i<=n;i+=4){
        if (k&1) cout <<i-1 <<' ' <<i <<endl;
        else cout <<i <<' ' <<i-1 <<endl;
    }
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}