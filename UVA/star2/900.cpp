#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n;
    ll ans[51]{0,1,2}; 
    for (int i=3;i<51;i++) ans[i] = ans[i-1] + ans[i-2];
    while (cin >>n && n!=0){
        cout <<ans[n] <<endl;
    }
}