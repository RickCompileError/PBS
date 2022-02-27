#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n, half;
    ll ans = 0;
    cin >>n, half = n/2;
    int p[n];
    for (int i=0;i<n;i++) cin >>p[i];
    sort(p,p+n);
    for (int i: p) ans += abs(p[half]-i);
    cout <<ans <<endl;
}