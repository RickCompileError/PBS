#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return (b==0?a:gcd(b,a%b));
}

int main(){
    string str;
    while (cin >>str && str!="0"){
        str = "0" + str.substr(2,str.size()-5);
        int mnd = 0, mnu = 0, d, u;
        for (int i=1;i<str.size();i++){
            d = pow(10,str.size()-1) - pow(10,str.size()-1-i);
            u = stod(str) - stod(str.substr(0,str.size()-i));
            if (mnd==0 || mnd>d/gcd(d,u)) mnd = d/gcd(d,u), mnu = u/gcd(d,u);
        }
        cout <<mnu <<"/" <<mnd <<endl;
    }
}