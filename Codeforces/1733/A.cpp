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
    int n, k;
    cin >>n >>k;
    ll arr[n], mx[k]{-1};
    for (int i=1;i<=n;i++) cin >>arr[i-1], mx[i%k] = max(mx[i%k], arr[i-1]);
    for (int i=1;i<k;i++) mx[i] += mx[i-1];
    cout <<mx[k-1] <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}