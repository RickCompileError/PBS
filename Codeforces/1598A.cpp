#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >>n;
        int game[2][n]{0};
        string str;
        for (int i=0;i<2;i++){
            cin >>str;
            for (int j=0;j<n;j++) game[i][j] = str[j] - '0';
        }
        int r = 0, c = 0;
        while (r!=1 || c!=n-1){
            game[r][c] = 1;
            if (!game[!r][c]) r = !r;
            else if (c+1<n && !game[r][c+1]) c++;
            else if (c+1<n && !game[!r][c+1]) r = !r, c++;
            else break;
        }
        cout <<(r==1&&c==n-1?"YES":"NO") <<endl;
    }
}