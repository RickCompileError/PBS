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
    int ans = 0;
    for (int i=0;i<n;i++){
        cin >>a[i];
        if (a[i]>a[ans]) ans = i;
    }
    cout <<ans+1 <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}