#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs; cin >>cs;
    while (cs--){
        int r; cin >>r;
        int s[r]; for (int i=0;i<r;i++) cin >>s[i];
        sort(s,s+r);
        int ans = 0;
        for (int i=0;i<r;i++) ans += abs(s[i]-s[r/2]);
        cout <<ans <<endl;
    }
}