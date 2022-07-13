#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t, n; cin >>t;
    while (t--){
        cin >>n;
        ll a[n+1]{0};
        ll count[n+1]{0};
        for (int i=1;i<=n;i++) cin >>a[i], count[i] = count[i-1] + (a[i]<i);
        ll ans = 0;
        for (int i=1;i<=n;i++){
            if (a[i]<i && a[i]>0) ans += count[a[i]-1];
        }
        cout <<ans <<endl;
    }

}