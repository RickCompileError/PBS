#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin >>n;
    while (n!=1){
        cout <<n <<' ';
        n = (n%2)?n*3+1:n/2;
    }
    cout <<1 <<endl;
}