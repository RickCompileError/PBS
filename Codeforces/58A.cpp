#include <bits/stdc++.h>

using namespace std;

int main(){
    string str; cin >>str;
    string hello = "hello";
    int s = 0;
    for (char i: str){
        if (i==hello[s]) s++;
        if (s==5) break;
    }
    cout <<(s==5?"YES":"NO") <<endl;
}