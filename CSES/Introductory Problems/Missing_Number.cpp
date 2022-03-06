#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5+1;

int main(){
    int n, p;
    cin >>n;
    bool appear[mx]{0};
    for (int i=1;i<n;i++){
        cin >>p;
        appear[p] = true;
    }
    for (int i=1;i<=n;i++){
        if (!appear[i]){
            cout <<i <<endl;
            return 0;
        }
    }
}