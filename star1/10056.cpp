#include <bits/stdc++.h>

using namespace std;

int main(){
    int s; cin >>s;
    while (s--){
        int n, serial;
        float p, np, cumulate, ans = 0;
        cin >>n >>p >>serial;
        np = 1-p;
        cumulate = pow(np,serial-1);
        while (cumulate*p>=1e-9){
            ans += cumulate*p;
            cumulate *= pow(np,n);
        }
        printf("%.04f\n",ans);
    }
}