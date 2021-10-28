#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs; cin >>cs;
    for (int i=1;i<=cs;i++){
        cout <<"Case " <<i <<": ";
        int a, b, amount; cin >>a >>b;
        if (a%2==0 && a+1<=b) a++;
        if (b%2==0 && b-1>=a) b--;
        amount = (b-a)/2+1;
        cout <<amount*(2*a+(amount-1)*2)/2 <<endl;
    }
}