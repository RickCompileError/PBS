#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll s,d;
    while (cin >>s >>d){
        ll minus = s*(s-1)/2;
        while (s*(s+1)/2-minus<d) s++;
        cout <<s <<endl;
    }
}