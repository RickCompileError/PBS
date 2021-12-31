#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll group = 45;

ll compute(int i){
    if (i<=0) return 0;
    ll ans = 0;
    while (i>0){
        for (int j=1;j<=i%10;j++) ans += j;
        i /= 10;
        ans += i*group;
    }
    return ans;
}

int main(){
    int p, q;
    while (cin >>p >>q && p>=0 && q>=0) cout <<compute(q)-compute(p-1) <<endl;
}