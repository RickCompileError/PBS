#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, ans = 0;
    map<int,bool> appear;
    cin >>n;
    while (n--){
        cin >>x;
        ans += !appear[x];
        appear[x] = 1;     
    }
    cout <<ans <<endl;
}