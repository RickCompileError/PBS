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

ll gcd(ll a, ll b){
    return a==1?b:gcd(b%a,a);
}

void solve(){
    int n; cin >>n;
    cout <<1LL*n/3*4+(n/2-n/3)*2+n <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}