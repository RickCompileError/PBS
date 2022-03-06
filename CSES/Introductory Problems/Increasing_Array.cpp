#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n, ans = 0;
    cin >>n;
    ll x[n];
    for (int i=0;i<n;i++) cin >>x[i];
    for (int i=1;i<n;i++) if (x[i]<x[i-1]) ans += x[i-1]-x[i], x[i] = x[i-1];
    cout <<ans <<endl;
}