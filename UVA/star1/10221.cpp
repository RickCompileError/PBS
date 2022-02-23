#include <bits/stdc++.h>

#define pi 2*acos(0)

using namespace std;

int main(){
    double s, a, r = 6440;
    double arc, chord;
    string unit;
    while (cin >>s >>a >>unit){
        if (unit=="min") a /= 60.0;
        if (a>180) a = 360 - a;
        arc = 2.0*(s+r)*pi*a/360.0;
        chord = 2*(s+r)*sin(2*pi*a/720.0);
        cout <<fixed <<setprecision(6) <<arc <<' ' <<chord <<endl;
    }
}