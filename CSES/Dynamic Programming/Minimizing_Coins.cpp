#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

const int mxX = 1e6, mxN = 1e2;
int c[mxN+1]{}, dp[mxX+1]{};

// 230ms
void solution1(){
    int n, x;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>c[i];
    fill_n(dp, mxX+1, INF);
    dp[0] = 0;
    for (int i=1;i<=x;i++){
        for (int j=0;j<n;j++){
            if (c[j]<=i && dp[i-c[j]]!=-1) dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    cout <<(dp[x]==INF?-1:dp[x]);
}

// 100ms
void solution2(){
    int n, x;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>c[i];
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i=0;i<n;i++){
        for (int j=c[i];j<=x;j++) dp[j] = min(dp[j], dp[j-c[i]]+1);
    }
    cout <<(dp[x]==INF?-1:dp[x]) <<endl;
}

int main(){
    solution2();
}