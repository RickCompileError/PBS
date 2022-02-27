#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n;
    cin >>n;
    ll x[n+1]{0};
    for (int i=1;i<=n;i++) cin >>x[i];
    sort(x,x+n+1);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        // it means ans + 1 can't create by using the subset of index 1 ~ i
        // x[i] must less than or equal to ans + 1 because index 1 ~ i-1 can only create to ans
        if (x[i]>ans+1) break;
        ans += x[i]; // update the maximum value of ans
    }
    cout <<ans+1 <<endl;
}