#include <bits/stdc++.h>

#define ll long long

using namespace std;

string str = "";

int main(){
    for (char i='0';i<='9';i++) str += i;
    for (char i='A';i<='Z';i++) str += i;
    for (char i='a';i<='z';i++) str += i;
    string in;
    while (cin >>in){
        ll sum = 0;
        int start = 0;
        for (char i: in){
            int base = str.find(i);
            if (base!=str.npos) sum += base, start = max(start,base);
        }
        for (;start>0 && start<=61 && sum%start!=0;start++);
        if (start>=62) cout <<"such number is impossible!\n";
        else if (start==0) cout <<2 <<endl;
        else cout <<start+1 <<endl;
    }
}