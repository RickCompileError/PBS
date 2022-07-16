#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int n; cin >>n;
    string a, b; cin >>a >>b;
    vector<int> va, vb;
    if (a[0]!=b[0] || a[n-1]!=b[n-1]){
        cout <<-1 <<endl;
        return;
    }
    for (int i=1;i<n;i++){
        if (a[i]!=a[i-1]) va.push_back(i);
        if (b[i]!=b[i-1]) vb.push_back(i);
    }
    if (va.size()!=vb.size()) cout <<-1 <<endl;
    else{
        ll ans = 0;
        for (int i=0,sz=va.size();i<sz;i++) ans += abs(va[i]-vb[i]);
        cout <<ans <<endl;
    }
}

int main(){
    int q; cin >>q;
    while (q--) solve();
}