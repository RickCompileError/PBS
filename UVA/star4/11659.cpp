// Brute-froce, time-out is possible if use three nested loop directly
// use bitwise operation to improve efficiency

#include <bits/stdc++.h>

using namespace std;

int main(){
    int I, a, x, y;
    while (cin >>I >>a && (I || a)){
        int pos[I+1]{0}, neg[I+1]{0};
        while (a--){
            cin >>x >>y;
            if (y>0) pos[x] |= 1<<(y-1);
            else neg[x] |= 1<<(-y-1);
        }
        int mx = 0;
        for (int i=0;i<1<<I;i++){
            int assume = i;
            bool illegal = false;
            for (int j=1;j<=I;j++){
                if ((assume & 1<<(j-1)) == 0) continue;
                if ((assume & neg[j]) > 0 || (assume | pos[j]) != assume){
                    illegal = true;
                    break;
                }
            }
            if (!illegal){
                int s = 0;
                while (assume>0){
                    s += assume & 1;
                    assume >>= 1;
                }
                mx = max(mx, s);
            }
        }
        cout <<mx <<endl;
    }
}