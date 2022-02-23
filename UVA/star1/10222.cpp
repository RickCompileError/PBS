#include <bits/stdc++.h>

using namespace std;

string sp="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main(){
    string s;
    while (getline(cin,s,'\n')){
        for (int i=0;i<s.size();i++){
            s[i] = tolower(s[i]);
            if (s[i]==' '){
                cout <<' ';
                continue;
            }
            for (int j=0;j<sp.size();j++) if (s[i]==sp[j]) cout <<sp[j-2];
        }
        cout <<endl;
    }
}