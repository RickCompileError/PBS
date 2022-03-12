#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >>n;
    int c[26]{0}, odd{0};
    for (char i: n) c[i-'A']++;
    for (int i: c) odd += (i%2!=0);
    if (odd>1) cout <<"NO SOLUTION\n";
    else{
        string es1="", os="", es2="";
        for (int i=0;i<26;i++){
            if (c[i]%2) for (int j=0;j<c[i];j++) os += (char)('A'+i);
            else for (int j=c[i]/2;j>0;j--) es1 += (char)('A'+i);
        }
        es2 = es1, reverse(es2.begin(),es2.end());
        cout <<es1 <<os <<es2;
    }
}