#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    while (getline(cin,a,'\n')){
        getline(cin,b,'\n');
        int c1[26]{0}, c2[26]{0};
        for (char i: a) c1[i-'a']++;
        for (char i: b) c2[i-'a']++;
        for (int i=0;i<26;i++)
            if (c1[i] && c2[i]) for (int j=0;j<min(c1[i],c2[i]);j++) cout <<(char)(i+'a');
        cout <<endl;
    }
}