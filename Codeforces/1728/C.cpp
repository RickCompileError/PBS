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

int dig(int n){
    return to_string(n).size();
}

void solve(){
    int n, u; cin >>n;
    priority_queue<int,vector<int>,less<int>> a, b;
    for (int i=0;i<n;i++) cin >>u, a.push(u);
    for (int i=0;i<n;i++) cin >>u, b.push(u);
    int ans = 0;
    while (a.size()>0 && b.size()>0){
        if (a.top()==b.top()){
            a.pop(), b.pop();
            continue;
        }
        if (a.top()>b.top()) a.push(dig(a.top())), a.pop();
        else b.push(dig(b.top())), b.pop();
        ans++;
    }
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}