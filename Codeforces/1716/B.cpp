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
    int a[n]; for (int i=1;i<=n;i++) a[i-1] = i;
    cout <<n <<endl;
    for (int i=0;i<n;i++){
        if (i!=0) swap(a[i],a[i-1]);
        for (int j=0;j<n;j++) cout <<a[j] <<' ';
        cout <<endl;
    }
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}