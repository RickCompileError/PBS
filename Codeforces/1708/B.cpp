#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n, l, r; cin >>n >>l >>r;
        l--;
        bool legal = true;
        for (int i=1;i<=n && legal;i++) legal = (l/i!=r/i);
        if (legal){
            cout <<"YES\n";
            for (int i=1;i<=n;i++) cout <<(l/i+1)*i <<(i==n?'\n':' ');
        }
        else cout <<"NO\n";
    }
}