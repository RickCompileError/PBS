#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >>n;
        int a[n];
        int l, g;
        l = g = -1;
        for (int i=0;i<n;i++){
            cin >>a[i];
            if (l==-1 || a[i]<a[l]) l = i;
            if (g==-1 || a[i]>a[g]) g = i;
        }
        if (l>g) swap(l,g);
        // x x x l x x g x x
        if (n==1) cout <<1 <<endl;
        else cout <<min((l+1), (n-g)) + min((g-l), max((l+1), (n-g))) <<endl;
    }
}