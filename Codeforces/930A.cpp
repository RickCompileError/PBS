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

const int mxN = 1e5+5;
vector<int> v[mxN];

void solve1(){
    int n, p;
    cin >>n;
    for (int i=2;i<=n;i++) cin >>p, v[p].pb(i);
    v[0].pb(1);
    int ans = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        vector<int> tmp;
        while (!q.empty()) tmp.pb(q.front()), q.pop();
        int tot = 0;
        for (int i: tmp) tot += v[i].size();
        ans += tot%2;
        for (int i: tmp) for (int j: v[i]) q.push(j);
    }
    cout <<ans <<endl;
}

int lv[mxN], tot[mxN];

void solve2(){
    int n, p;
    cin >>n;
    tot[0] = 1;
    for (int i=2;i<=n;i++){
        cin >>p;
        lv[i] = lv[p] + 1;
        tot[lv[i]]++;
    }
    int ans = 0;
    for (int i: tot) ans += i % 2;
    cout <<ans <<endl;
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve2();
}