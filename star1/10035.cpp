#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll a,b;
    while (cin >>a >>b && (a!=0 || b!=0)){
        int carry = 0, ans = 0;
        while (a>0 || b>0 || carry){
            carry = (a%10+b%10+carry>=10);
            if (carry) ans++;
            a /= 10;
            b /= 10;
        }
        if (ans==0) cout <<"No carry operation.\n";
        else if (ans==1) cout <<"1 carry operation.\n";
        else cout <<ans <<" carry operations.\n";
    }
}