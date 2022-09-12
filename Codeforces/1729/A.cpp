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
    int a, b, c;
    cin >>a >>b >>c;
    a = a-1;
    b = abs(b-c) + (c-1);
    if (a<b) cout <<1;
    else if (a>b) cout <<2;
    else cout <<3;
    cout <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}