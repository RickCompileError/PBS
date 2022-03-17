#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int n;
ll ans = LLONG_MAX;
ll p[20]; // maximum size 20

void dp(int pos, ll sum){
    if (pos==n) ans = min(ans,abs(sum));
    else{
        dp(pos+1, sum+p[pos]);
        dp(pos+1, sum-p[pos]);
    }
}

int main(){
    cin >>n;
    for (int i=0;i<n;i++) cin >>p[i];
    dp(0, 0);
    cout <<ans <<endl;
}