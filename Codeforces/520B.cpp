#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >>n >>m;
    int a[20005];
    memset(a, 0x3f, sizeof(a));
    for (int i=1;i<=n;i++) a[i] = n-i;
    for (int i=1,sz=m/2+1;i<=sz;i++){
        a[i*2] = min(a[i*2], a[i]+1);
        a[i*2-1] = min(a[i*2-1], a[i]+2);
    }
    cout <<a[m] <<endl;
}