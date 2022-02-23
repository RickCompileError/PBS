#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    while (cin >>a >>b && a!=0 && b!=0){
        cout <<(int)sqrt(b)-ceil(sqrt(a))+1 <<endl;
    }
}