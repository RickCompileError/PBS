/* 
    must use double
    can't use cout to print answer
 */

#include <bits/stdc++.h>

using namespace std;

double eps=1e-9;

int main(){
    double l, w;
    while (cin >>l >>w){
        printf("%.3lf %.3lf %.3lf\n",(4.0*(l+w)-sqrt(pow(-4*(l+w),2)-4.0*12.0*l*w))/24.0,0.000,(l<=w?l/2.0:w/2.0)+eps);
    }
}