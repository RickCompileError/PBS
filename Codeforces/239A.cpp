#include <bits/stdc++.h>

using namespace std;

int main(){
    int y, k, n;
    cin >>y >>k >>n;
    n = n-y;
    y = k-(y%k);
    if (y<=n) for (;y<=n;y+=k) cout <<y <<(y+k>n?'\n':' ');
    else cout <<"-1\n";
}