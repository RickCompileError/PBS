#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n; cin >>n;
    for (int i=1;i<=n;i++){
        cout <<"Case " <<i <<": ";
        ll x1, y1, x2, y2, ans = 0;
        cin >>x1 >>y1 >>x2 >>y2;
        if (x2-x1==y1-y2) ans = abs(x1-x2);
        else{
            ll h1 = x1+y1+1, h2 = x2+y2;
            ans += x2 + y1 + 1;
            ans += (h2*(h2+1)-h1*(h1+1))/2;
        }
        cout <<ans <<endl;
    }
}