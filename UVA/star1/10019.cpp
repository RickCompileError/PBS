#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >>n;
    while (n--){
        string s; cin >>s;
        bitset<32> b1(stoi(s,0,10)), b2(stoi(s,0,16));
        cout <<b1.count() <<' ' <<b2.count() <<endl;
    }
}