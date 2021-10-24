#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs; cin >>cs;
    while (cs--){
        int len, n; cin >>len >>n;
        int pos[n]; for (int i=0;i<n;i++) cin >>pos[i];
        int half = len/2, mn = 0, left = len, right = 0;
        for (int i: pos){
            if (i<=half) mn = max(mn,i);
            else mn = max(mn,len-i);
            left = min(left,i);
            right = max(right,i);
        }
        cout <<mn  <<' ' <<max(len-left,right) <<endl;
    }
}