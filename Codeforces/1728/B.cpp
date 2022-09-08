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
    if (n%2) cout <<n-3 <<' ' <<n-2 <<' ';
    else cout <<n-2 <<' ' <<n-3 <<' ';
    for (int i=n-4;i>=1;i--) cout <<i <<' ';
    cout <<n-1 <<' ' <<n <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}
