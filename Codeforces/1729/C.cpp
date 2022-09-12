#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pci pair<char,int>
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
    string str; cin >>str;
    set<int> st[26];
    for (int i=0,sz=str.size();i<sz;i++) st[str[i]-'a'].insert(i+1);
    int s = str[0]-'a', e=str.back()-'a', sum=0;
    for (int i=min(s,e);i<=max(s,e);i++) sum += st[i].size();
    cout <<abs(str.front()-str.back()) <<' ' <<sum <<endl;
    if (s>e) for (;s>=e;s--) for (int i: st[s]) cout <<i <<' ';
    else for (;s<=e;s++) for (int i: st[s]) cout <<i <<' ';
    cout <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}