#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int n, m; cin >>n >>m;
    string str(m,'B');
    int a;
    for (int i=0;i<n;i++){
        cin >>a, a--;
        a = min(a,m-1-a);
        (str[a]=='A'?str[m-1-a]='A':str[a]='A');
    }
    cout <<str <<endl;
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}