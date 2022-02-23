#include <bits/stdc++.h>

using namespace std;

const double pi = 2*acos(0);

int main(){
    double r;
    while (cin >>r){
        double a = r*r - (r*r*pi/6) - (r*r*sqrt(3.0)/4);
        double b = r*r - (r*r*pi/4) - (2*a);
        double c = r*r - 4*(a+b);
        cout <<fixed <<setprecision(3) <<c <<' ' <<4*b <<' ' <<4*a <<endl;
    }
}