#include <bits/stdc++.h>

using namespace std;

const int mxM = 1e2;
int m, n, q, r, c;
string str[mxM];

int find_bound(){
    int count = 0;
    while (r-count>=0 && r+count<m && c-count>=0 && c+count<n){
        for (int i=r-count;i<=r+count;i++)
            for (int j=c-count;j<=c+count;j++)
                if (str[i][j]!=str[r][c]) return count-1;
        count++;
    }
    return count-1;
}

int main(){
    int t; cin >>t;
    while (t--){
        cin >>m >>n >>q;
        cout <<m <<' ' <<n <<' ' <<q <<endl;
        for (int i=0;i<m;i++) cin >>str[i];
        while (q--){
            cin >>r >>c;
            cout <<1+2*find_bound() <<endl;
        }
    }
}