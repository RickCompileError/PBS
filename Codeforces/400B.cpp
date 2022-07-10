#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, mn = INT_MAX; cin >>n >>m;
    bool legal = true;
    while (n--){
        string str; cin >>str;
        int g{-1}, s{-1};
        for (int i=0;i<m;i++){
            if (str[i]=='G') g = i;
            if (str[i]=='S') s = i;
        }
        if (g<s) mn = min(mn, s-g);
        if (g>s) legal = false;
    }
    cout <<(legal?mn:-1) <<endl;
}