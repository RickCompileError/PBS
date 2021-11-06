#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >>n){
        int a[n+1];
        for (int i=1;i<=n;i++) cin >>a[i];
        sort(a+1,a+n+1);
        int ct = count(a+1,a+n+1,a[n/2+1]);
        if (n%2==0 && a[n/2]!=a[n/2+1]) ct += count(a+1,a+n+1,a[n/2]);
        if (n%2) cout <<a[n/2+1] <<" " <<ct <<" " <<1 <<endl;
        else cout <<a[n/2] <<" " <<ct <<" " <<a[n/2+1]-a[n/2]+1 <<endl;
    }
}