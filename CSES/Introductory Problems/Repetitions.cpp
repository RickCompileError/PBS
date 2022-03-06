#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >>n;
    char current = 'X';
    int time, ans = 0;
    for (char i: n){
        (i==current)?(time++):(current=i,time=1);
        ans = max(ans,time);
    }
    cout <<ans <<endl;
}