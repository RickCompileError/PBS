#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e3, mod = 1e9+7;
string str[mxN+1];
ll dp[mxN+1][mxN+1];

// 40ms
void solution1(){
    int n;
    cin >>n;
    dp[0][1] = 1;
    for (int i=0;i<n;i++) cin >>str[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dp[i][j] = (str[i-1][j-1]=='*'?0:dp[i-1][j]+dp[i][j-1]);
            if (dp[i][j]>=mod) dp[i][j] -= mod;
        }
    }
    cout <<dp[n][n];
}

// 40ms
void solution2(){
    int n;
    string s;
    cin >>n;
    dp[0][1] = 1;
    for (int i=1;i<=n;i++){
        cin >>s;
        for (int j=1;j<=n;j++){
            if (s[j-1]=='.') dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else dp[i][j] = 0;
            if (dp[i][j]>=mod) dp[i][j] -= mod;
        }
    }
    cout <<dp[n][n];
}

int main(){
    solution2();
}