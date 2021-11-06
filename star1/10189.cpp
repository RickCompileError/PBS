#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, cs = 1;
    bool first = true;
    while (cin >>n >>m && n!=0 && m!=0){
        if (!first) cout <<endl;
        printf("Field #%d:\n",cs++);
        char c[n+2][m+2];
        int ans[n+2][m+2]{{0}};
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >>c[i][j];
                if (c[i][j]=='*'){
                    ans[i-1][j-1]++, ans[i-1][j]++, ans[i-1][j+1]++;
                    ans[i][j-1]++, ans[i][j+1]++;
                    ans[i+1][j-1]++, ans[i+1][j]++, ans[i+1][j+1]++;
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (c[i][j]=='*') cout <<'*';
                else cout <<ans[i][j];
            }
            cout <<endl;
        }
        first = false;
    }
}