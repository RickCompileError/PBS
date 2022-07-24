/* Using dfs can cause memory limit exceed */
#include <bits/stdc++.h>
 
#define price pair<int,ll>
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
 
const int mxN = 1e5+1, mxM = 1e5+1;
int c[mxN]{}, s[mxN]{};
bool b[mxN]{};

int find(int x){
    return (x==s[x]?x:s[x]=find(s[x]));
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if (x==y) return;
    if (c[x]<=c[y]) s[y] = x;
    else s[x] = y;
}
 
int main(){
    int n, m, x, y; cin >>n >>m;
    for (int i=1;i<=n;i++) cin >>c[i], s[i] = i;
    for (int i=0;i<m;i++){
        cin >>x >>y;
        merge(x, y);
    }
    // there may be some set haven't been updated yet
    for (int i=1;i<=n;i++) find(i);
    ll ans = 0;
    for (int i=1;i<=n;i++) if (!b[s[i]]) ans += c[s[i]], b[s[i]] = true;
    cout <<ans;
}