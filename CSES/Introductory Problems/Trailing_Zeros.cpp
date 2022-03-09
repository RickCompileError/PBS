#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ans = 0;
    cin >>n;
    while (n){
        ans += n/5;
        n /= 5;
    }
    cout <<ans <<endl;
}