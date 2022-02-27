#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n, x;
    cin >>n;
    ll mx = -1e9-1, current = 0;
    while (n--){
        cin >>x;
        if (x>current && current<0) current = 0;
        current += x;
        mx = max(mx, current);
    }
    cout <<mx <<endl;
}