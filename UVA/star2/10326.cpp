/* 
    Warning: The code is correct but can't pass on online-judge because some bugs in their testing input.
 */
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxN = 55;
ll coef[mxN], root[mxN];
int N;

int main(){
    while (cin >>N){
        memset(root,0,sizeof(root));
        fill_n(coef,mxN,1);
        for (int i=0;i<N;i++) cin >>root[i], root[i] = -root[i];
        for (int i=0;i<N;i++){
            for (int j=i;j>=0;j--) coef[j] = (j>0?coef[j-1]:0)+coef[j]*root[i];
        }
        cout <<"x^" <<N;
        for (int i=N-1;i>=0;i--){
            if (i>=1){
                if (coef[i]==0) continue;
                cout <<' ' <<(coef[i]>0?'+':'-') <<' ';
                if (abs(coef[i])>1) cout <<abs(coef[i]);
                cout <<'x';
                if (i>1) cout <<'^' <<i;
            } else cout <<' ' <<(coef[i]>=0?'+':'-') <<' ' <<abs(coef[i]);
        }
        cout <<" = 0\n";
    }
}