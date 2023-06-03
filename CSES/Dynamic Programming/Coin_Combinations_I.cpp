#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e2, mxX = 1e6, mod = 1e9+7;
ll c[mxN+1]{}, dp[mxX+1]{};

// 530ms
void solution1(){
    int n, x;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>c[i];
    dp[0] = 1;
    for (int i=1;i<=x;i++)
        for (int j=0;j<n;j++)
            dp[i] = (dp[i] + (i>=c[j]?dp[i-c[j]]:0)) % mod;
    cout <<dp[x] <<endl;
}

// 140ms
void solution2(){
    int n, x;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>c[i];
    dp[0] = 1;
    for (int i=1;i<=x;i++){
        for (int j=0;j<n;j++){
            if (i>=c[j]) dp[i] += dp[i-c[j]];
        }
        dp[i] %= mod;
    }
    cout <<dp[x] <<endl;
}

int main(){
    solution2();
}