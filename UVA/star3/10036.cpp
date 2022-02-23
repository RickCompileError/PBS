#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs; cin >>cs;
    while (cs--){
        int n, k; cin >>n >>k;
        int num[n]; for (int i=0;i<n;i++) cin >>num[i], num[i] = abs(num[i])%k;
        bool ans[n+1][k];
        memset(ans,0,sizeof(ans));
        ans[0][0] = 1;
        for (int i=0;i<n;i++)
            for (int j=0;j<k;j++)
                if (ans[i][j]) ans[i+1][(j+k+num[i])%k] = ans[i+1][(j+k-num[i])%k] = 1;
        cout <<(ans[n][0]?"Divisible":"Not divisible") <<endl;
    }
}