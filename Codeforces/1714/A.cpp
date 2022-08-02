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
    int n, H, M; cin >>n >>H >>M;
    int s1 = H*60+M;
    int h[n], m[n]; for (int i=0;i<n;i++) cin >>h[i] >>m[i];
    int s[n]; for (int i=0;i<n;i++) s[i] = h[i]*60 + m[i];
    int ans = INT_MAX;
    for (int i=0;i<n;i++){
        if (s[i]<s1) ans = min(ans, s[i]+1440-s1);
        else ans = min(ans, s[i]-s1);
    }
    cout <<ans/60 <<' ' <<ans%60 <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}