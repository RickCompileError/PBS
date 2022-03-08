#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll t, y, x;
    cin >>t;
    while (t--){
        cin >>y >>x;
        ll ans = max(y,x);
        int dir = (ans%2)?1:-1; // if even, left-right pos up-down neg, vice versa.
        ans = ans*ans-ans+1; // calculate lower-right corner
        ans += dir*(x-y); // offset up or left
        cout <<ans <<endl;
    }    
}