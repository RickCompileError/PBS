#include <bits/stdc++.h>

using namespace std;

int dooms[13]{0,10,21,7,4,9,6,11,8,5,10,7,12};
string week[7]{"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int main(){
    int cs, m, d; cin >>cs;
    while (cs--){
        cin >>m >>d;
        if (d>=dooms[m]) cout <<week[(d-dooms[m])%7] <<endl;
        else cout <<week[7-((dooms[m]-d-1)%7+1)] <<endl;
    }   
}