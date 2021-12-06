#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e2;
int arr[mxN+1][mxN+1]{{}};

int main(){
    int n; cin >>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            cin >>arr[i][j];
            arr[i][j] += arr[i][j-1];
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            arr[i][j] += arr[i-1][j];
    int ans = INT_MIN;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int x=0;x<=i-1;x++)
                for (int y=0;y<=j-1;y++)
                    ans = max(ans,arr[i][j]-arr[x][j]-arr[i][y]+arr[x][y]);
    cout <<ans <<endl;
}