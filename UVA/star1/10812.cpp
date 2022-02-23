#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n; cin >>n;
    while (n--){
        ll s, d, a; cin >>s >>d;
        a = (s+d)/2;
        if (s<d || (s-d)%2) cout <<"impossible" <<endl;
        else cout <<max(a,s-a) <<' ' <<min(a,s-a) <<endl;
    }
}