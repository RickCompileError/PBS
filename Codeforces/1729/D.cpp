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
    vector<ll> x(n), y(n);
    for (int i=0;i<n;i++) cin >>x[i];
    for (int i=0;i<n;i++) cin >>y[i];
    vector<int> neg, pos;
    int eq = 0, ans = 0;
    for (int i=0;i<n;i++){
        if (x[i]>y[i]) neg.pb(abs(x[i]-y[i]));
        else if (x[i]<y[i]) pos.pb(y[i]-x[i]);
        else eq++;
    }
    sort(neg.begin(),neg.end()), sort(pos.begin(),pos.end());
    int i=0, j=0, remain=0;
    while (i<neg.size() && j<pos.size()){
        if (neg[i]>pos[j]) while (j<pos.size() && pos[j]<neg[i]) j++, remain++; 
        if (j<pos.size()) ans++, i++, j++;
    }
    remain += pos.size()-j;
    ans += (remain+eq)/2;
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}