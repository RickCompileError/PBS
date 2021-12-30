#include <bits/stdc++.h>

using namespace std;

const int mxM = 1e6;
int ans[2][mxM];

int main(){
    int n, m, d; cin >>n;
    bool first = true;
    while (n--){
        if (!first) cout <<endl;
        memset(ans,0,sizeof(ans));
        cin >>m;
        for (int i=mxM-m;i<mxM;i++) cin >>ans[0][i] >>ans[1][i];
        int i = mxM-1, carry = 0;
        for (;i>=mxM-m || carry;i--){
            ans[0][i] += ans[1][i] + carry;
            carry = (ans[0][i]>=10);
            ans[0][i] %= 10;
        }
        for (i++;i<mxM;i++) cout <<ans[0][i];
        cout <<endl;
        first = false;
    }
}