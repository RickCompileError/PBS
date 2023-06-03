#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mod = 1e9+7;
const int mxN = 1e6+1;
int dp[mxN]{};

int main(){
    int n;
    cin >>n;
    dp[0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=(i-6>=0?i-6:0);j<i;j++) dp[i] = (dp[i] + dp[j]) % mod;
    }
    cout <<dp[n];
}