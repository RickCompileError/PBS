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
    int n, x; cin >>n >>x;
    int a[n]; for (int i=0;i<n;i++) cin >>a[i];
    int cur = 0, count = -1;
    while (cur<n){
        int mx{a[cur]}, mn{a[cur]}, end = cur+1;
        while (end<n){
            mx = max(mx, a[end]);
            mn = min(mn, a[end]);
            if ((mx-mn)>2*x) break;
            end++;
        }
        cur = end;
        count++;
    }
    cout <<count <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}