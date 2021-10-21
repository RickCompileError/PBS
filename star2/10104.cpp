#include <bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int a, int b, int &x, int &y){
    if (b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

int main(){
    ll a,b;
    while (cin >>a >>b){
        int x, y, g;
        g = gcd(a,b,x,y);
        cout <<x <<' ' <<y <<' ' <<g <<endl;
    }
}