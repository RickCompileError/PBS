#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n, x, sz; cin >>n >>x; sz = 2*n;
        int h[sz]; for (int i=0;i<sz;i++) cin >>h[i];
        sort(h, h+sz);
        bool legal = true;
        for (int i=0;i<n&&legal;i++) if (h[i+n]-h[i]<x) legal = false;
        cout <<(legal?"YES":"NO") <<endl;
    }
}