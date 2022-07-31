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
    int n, m; cin >>n >>m;
    string a, b; cin >>a >>b;
    for (int i=1;i<m;i++){
        if (a.back()!=b.back()){
            cout <<"NO" <<endl;
            return;
        }
        a.pop_back();
        b.pop_back();
    }
    if (b[0]=='0' && a==string(a.size(),'1')){
        cout <<"NO" <<endl;
        return;
    }
    if (b[0]=='1' && a==string(a.size(),'0')){
        cout <<"NO" <<endl;
        return;
    }
    cout <<"YES";
    cout <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}