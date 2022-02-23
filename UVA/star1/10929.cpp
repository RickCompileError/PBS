#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while (cin >>s && s!="0"){
        int s1 = 0, s2 = 0;
        for (int i=0;i<s.size();i++){
            if (i%2) s1 += s[i]-'0';
            else s2 += s[i]-'0';
        } 
        if ((s1-s2)%11==0) cout <<s <<" is a multiple of 11.\n";
        else cout <<s <<" is not a multiple of 11.\n";
    }
}