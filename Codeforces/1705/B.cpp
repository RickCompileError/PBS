#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >>n;
        ll a[n+1]{0};
        for (int i=1;i<=n;i++){
            cin >>a[i];
            if (i==n) break;
            a[i] += a[i-1] + (a[i-1]!=0 && a[i]==0);
        }
        cout <<a[n-1] <<endl;
    }
}