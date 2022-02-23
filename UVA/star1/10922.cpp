#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while (cin >>s && s!="0"){
        cout <<s;
        int sum = 0;
        for (char i: s) sum += i-'0';
        int ans = 0;
        while (sum%9==0 && sum!=9){
            ans++;
            int tmp = sum;
            sum = 0;
            while (tmp>0) sum += tmp%10, tmp /= 10;
        }
        if (sum==9) ans++;
        if (ans>0) printf(" is a multiple of 9 and has 9-degree %d.\n",ans);
        else printf(" is not a multiple of 9.\n");
    }
}