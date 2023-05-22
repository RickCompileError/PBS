#include <bits/stdc++.h>

using namespace std;

/* 
 * Not really understand why the code can work
 * The code is ref from https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/1366.php
 */
void sol1(){
    int n, m;
    while (cin >>n >>m && n|m){
        int y[n][m], b[n][m], y2[n][m], b2[n][m], dp[n][m]{};
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >>y[i][j];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >>b[i][j];
        // each row, cumulative sum from east to west
        for (int i=n-1;i>=0;i--){
            y2[i][m-1] = y[i][m-1];
            for (int j=m-2;j>=0;j--) y2[i][j] = y2[i][j+1] + y[i][j];
        }
        // each col, cumulative sum from south to north
        for (int i=n-2;i>=0;i--) for (int j=m-1;j>=0;j--) y2[i][j] += y2[i+1][j];
        // each row, cumulative sum from east to west
        for (int i=n-1;i>=0;i--){
            b2[i][m-1] = b[i][m-1];
            for (int j=m-2;j>=0;j--) b2[i][j] = b2[i][j+1] + b[i][j];
        }
        // each col, cumulative sum from south to north
        for (int i=n-2;i>=0;i--) for (int j=m-1;j>=0;j--) b2[i][j] += b2[i+1][j];
        // I don't really know why line 26~28 won't cause the problem, like the bottom line is left up left
        dp[n-1][m-1] = max(y[n-1][m-1], b[n-1][m-1]);
        for (int i=n-2;i>=0;i--) dp[i][m-1] = max(y2[i][m-1], b[i][m-1]+dp[i+1][m-1]);
        for (int i=m-2;i>=0;i--) dp[n-1][i] = max(b2[n-1][i], y[n-1][i]+dp[n-1][i+1]);
        for (int i=n-2;i>=0;i--) for (int j=m-2;j>=0;j--) dp[i][j] = max(dp[i][j+1]+y2[i][j]-y2[i][j+1], dp[i+1][j]+b2[i][j]-b2[i+1][j]);
        cout <<dp[0][0] <<endl;
    }
}

// more reasonable and can know why it can work
void sol2(){
    int n, m;
    vector<vector<int>> y(501, vector<int>(501)), b(501, vector<int>(501));
    int dp[501][501][2]{};
    while (cin >>n >>m && n|m){
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >>y[i][j], y[i][j] += y[i][j-1];
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >>b[i][j], b[i][j] += b[i-1][j];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]) + y[i][j];
                dp[i][j][1] = max(dp[i][j-1][0], dp[i][j-1][1]) + b[i][j];
            }
        }
        cout <<max(dp[n][m][0], dp[n][m][1]) <<endl;
    }
}

int main(){
    sol2();
}