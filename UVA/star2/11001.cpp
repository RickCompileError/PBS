/* 
    To deal with floating point deviation, we need to transform function.

    D = 0.3*sqrt(vt/i-v)
    len = D*i
    
    len = 0.3*sqrt(vt/i-v)*i
    len^2 = 0.09*(vt/i-v)*i^2
    len^2 ~= vt*i - v*i^2
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    double vt, v;
    while (cin >>vt >>v && vt!=0 && v!=0){
        int num = 0, ctn = 0, i = 1;
        double mx = 0, result;
        while (vt/i>v){
            result = vt*i - v*i*i;
            if (result>mx){
                num = i;
                ctn = 0;
                mx = result;
            }
            else if (result==mx) ctn++;
            i++;
        }
        if (!ctn) cout <<num <<endl;
        else cout <<0 <<endl;
    }
}