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
    int n, q;
    cin >>n >>q;
    int a[n+1]{0}, win[n+1]{0}, ind[q+1]{0}, k[q+1]{0}, ans[q+1]{0};
    vector<int> round[n+1];
    for (int i=1;i<=n;i++) cin >>a[i];
    for (int i=1;i<=q;i++){
        cin >>ind[i] >>k[i];
        if (k[i]>n) round[n].pb(i);
        else round[k[i]].pb(i);
    }
    int winner = 1;
    for (int i=2;i<=n;i++){
        if (a[i]>a[winner]) winner = i;
        win[winner]++;
        for (int j: round[i-1]){
            ans[j] = win[ind[j]];
        }
    }
    for (int i: round[n]) ans[i] = win[ind[i]] + (ind[i]==winner?k[i]-n+1:0);
    for (int i=1;i<=q;i++) cout <<ans[i] <<endl;
}

void solve2(){
    int n, q, ind, k;
    cin >>n >>q;
    int a[n+1]{0};
    for (int i=1;i<=n;i++) cin >>a[i];
    vector<int> win[n+1];
    int winner = 1;
    for (int i=2;i<=n;i++){
        if (a[i]>a[winner]) winner = i;
        win[winner].pb(i-1);
    }
    while (q--){
        cin >>ind >>k;
        int ans = lower_bound(win[ind].begin(), win[ind].end(), k+1) - win[ind].begin();
        if (ind==winner) ans += max(0, k-n+1);
        cout <<ans <<endl;
    }
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve2();
}