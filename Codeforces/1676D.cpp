#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n, m, mx, mn; cin >>n >>m;
        mx = max(n,m), mn = min(n,m);
        int arr[n][m], left_dg[2][mx], right_dg[2][mx];
        memset(left_dg, 0, sizeof(left_dg)), memset(right_dg, 0, sizeof(right_dg));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin >>arr[i][j];
                if (i<=j) left_dg[0][j-i] += arr[i][j];
                else left_dg[1][i-j] += arr[i][j];
                if (i+j<m) right_dg[0][i+j] += arr[i][j];
                else right_dg[1][i+j-m] += arr[i][j];
            }
        }
        int ans = -1;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int tmp = 0;
                tmp += (i<=j?left_dg[0][j-i]:left_dg[1][i-j]);
                tmp += (i+j<m?right_dg[0][i+j]:right_dg[1][i+j-m]);
                ans = max(ans, tmp-arr[i][j]);
            }
        }
        cout <<ans <<endl;
    }
}