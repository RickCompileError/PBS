#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k, ans = 0;
    cin >>n >>m >>k;
    int a[n], b[m];
    for (int i=0;i<n;i++) cin >>a[i];
    for (int i=0;i<m;i++) cin >>b[i];
    sort(a,a+n), sort(b,b+m);
    for (int i=0,j=0;i<n;i++){
        while (j<m && b[j]<a[i]-k) j++;
        if (j<m && b[j]<=a[i]+k) j++, ans++;
    }
    cout <<ans <<endl;
}