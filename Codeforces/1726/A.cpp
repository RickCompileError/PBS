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
    int n;
    cin >>n;
    int a[n];
    for (int i=0;i<n;i++) cin >>a[i];
    if (n==1){
        cout <<0 <<endl;
        return;
    }
    int ans = -1000;
    for (int i=1;i<n;i++) ans = max(ans, a[i]-a[0]);
    for (int i=0;i<n-1;i++) ans = max(ans, a[n-1]-a[i]);
    for (int i=0;i<n-1;i++) ans = max(ans, a[i]-a[i+1]);
    ans = max(ans, a[n-1]-a[0]);
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}