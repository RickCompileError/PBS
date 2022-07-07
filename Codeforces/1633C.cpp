#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        ll hc, dc, hm, dm, k, w, a, tc;
        cin >>hc >>dc >>hm >>dm >>k >>w >>a;
        bool win = false;
        for (int i=0;i<=k && !win;i++){
            tc = (hc+a*i)/dm - ((hc+a*i)%dm==0?1:0) + 1; // player can attack at least one time
            win = ceil((double)hm/(dc+w*(k-i))) <= tc;
        }
        cout <<(win?"YES":"NO") <<endl;
    }
}