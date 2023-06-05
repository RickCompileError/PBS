#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e2, mxX = 1e6, mod = 1e9+7;
ll c[mxN+1]{}, dp[mxX+1]{};

// 220ms
void solution1(){
    int n, x;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>c[i];
    dp[0] = 1;
    for (int i=0;i<n;i++){
        for (int j=c[i];j<=x;j++){
            dp[j] += dp[j-c[i]];
            dp[j] %= mod;
        }
    }
    cout <<dp[x] <<endl;
}

// 140ms
void solution2(){
    int n, x;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>c[i];
    dp[0] = 1;
    for (int i=0;i<n;i++){
        for (int j=c[i];j<=x;j++){
            dp[j] += dp[j-c[i]];
            if (dp[j]>=mod) dp[j] -= mod;
        }
    }
    cout <<dp[x] <<endl;
}

int main(){
    solution2();
}