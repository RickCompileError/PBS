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
#define rep(i, l, r) for (int i=l;i<=r;i++)
#define repn(i, l, r) for (int i=l;i<r;i++)

using namespace std;

void solve(){
    int n; cin >>n;
    string str; cin >>str;
    int ans = 0;
    char last = '.';
    for (char i: str){
        if (i=='(') ans += last!=')';
        last = i;
    }
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}