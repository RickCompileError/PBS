#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        string str; cin >>str;
        for (int i=0;i<str.size();i++) str[i] = toupper(str[i]);
        cout <<(str=="YES"?"YES":"NO") <<endl;
    }
}