// Catalan Numbers Problem

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n;
    ll ans[22][22]{{0},{1,1}};
    for (int i=2;i<22;i++){
        ans[i][0] = ans[i][i] = 1;
        for (int j=1;j<i;j++) ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
    }
    bool next = false;
    while (cin >>n){
        if (next) cout <<endl;
        cout <<ans[2*n][n]-ans[2*n][n-1] <<endl;
        next = true;
    }
}