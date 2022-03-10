#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, a, b;
    cin >>t;
    while (t--){
        cin >>a >>b;
        if ((a+b)%3 || (abs(a-b)>(a+b)/3)) cout <<"NO\n";
        else cout <<"YES\n";
    }
}

// x+2y = a, 2x+y = b
// 3x+3y = a+b
// 3 9 4