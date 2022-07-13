#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxN = 1e2+5;
int n;
int ans;
int a[mxN][mxN];

void rotate(){
    for (int i=0,szr=n/2;i<szr;i++){
        for (int j=i,szc=n-1-i;j<szc;j++){
            int f = a[i][j]+a[j][n-1-i]+a[n-1-i][n-1-j]+a[n-1-j][i];
            ans += min(f, 4-f);
        }
    }
}

int main(){
    int t; cin >>t;
    while (t--){
        cin >>n;
        memset(a, 0, sizeof(a));
        ans = 0;
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%1d", &a[i][j]);
        rotate();
        cout <<ans <<endl;
    }
}