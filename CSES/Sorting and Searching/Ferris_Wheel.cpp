#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >>n >>x;
    int p[n], ans = n;
    for (int i=0;i<n;i++) cin >>p[i];
    sort(p,p+n);
    for (int i=0,j=n-1;j>i;j--)
        if (p[i]+p[j]<=x) ans--, i++;
    cout <<ans <<endl;
}