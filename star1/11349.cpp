#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int cs, n; cin >>cs;
    for (int t=1;t<=cs;t++){
        printf("Test #%d: ",t);
        cin.ignore(5); cin >>n;
        ll m[n][n];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >>m[i][j];
        bool legal = true;
        for (int i=0;i<n && legal;i++)
            for (int j=i;j<n && legal;j++)
                if (m[i][j]<0 || m[i][j]!=m[n-1-i][n-1-j]) legal = false;
        if (legal) cout <<"Symmetric.\n";
        else cout <<"Non-symmetric.\n";
    }
}