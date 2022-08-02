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
    int n; cin >>n;
    int a[n]; for (int i=0;i<n;i++) cin >>a[i];
    map<int,bool> m;
    int ans = n-1;
    for (;ans>=0;ans--){
        if (m[a[ans]]) break;
        m[a[ans]] = true;
    }
    cout <<ans+1 <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}