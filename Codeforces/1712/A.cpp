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
    int n, k, p;
    cin >>n >>k;
    int ans = 0;
    for (int i=1;i<=n;i++) cin >>p, ans += (p>k && i<=k);
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}