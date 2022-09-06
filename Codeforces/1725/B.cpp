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
    int N, D;
    cin >>N >>D;
    int p[N]; for (int i=0;i<N;i++) cin >>p[i];
    sort(p, p+N);
    int ans = 0;
    for (int i=N-1;i>=0;i--){
        if (N>=(D/p[i])+1) ans++, N -= (D/p[i])+1;
        else break;
    }
    cout <<ans <<endl;
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}