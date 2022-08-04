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
#define rep(i, l, r) for (int i=l;i<=r;i++)
#define repn(i, l, r) for (int i=l;i<r;i++)

using namespace std;

const int mod = 998244353;

int add(int i, int j){
    if (i+j>=mod) return i + j - mod;
    return i + j;
}

void solve(){
    ll n, k;
    cin >>n >>k;
    int dpprev[n+1]{0}, dpcur[n+1]{0}, ans[n+1]{0}, sum = 0;
    dpprev[0] = 1;
    rep(i, 0, 700){
        if (sum>n) break;
        memset(dpcur, 0, sizeof(dpcur));
        rep(j, sum+i+k, n){
            dpcur[j] = add(dpprev[j-i-k], dpcur[j-i-k]);
            ans[j] = add(ans[j], dpcur[j]);
        }
        memcpy(dpprev, dpcur, sizeof(dpcur));
        sum += i + k;
    }
    rep(i, 1, n){
        ans[i] = add(ans[i], dpprev[i]);
        cout <<ans[i] <<' ';
    }
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}