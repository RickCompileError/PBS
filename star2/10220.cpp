#include <bits/stdc++.h>

using namespace std;

vector<int> fct[1001];

void print(){
    for (int i=1000;i<=1000;i++){
        for (auto j=fct[i].rbegin();j!=fct[i].rend();j++) cout <<(*j);
        cout <<endl;
    }
}

void build(){
    fct[0].push_back(1);
    fct[1].push_back(1);
    for (int i=2;i<=1000;i++){
        int carry = 0, mul;
        for (int j: fct[i-1]){
            mul = i*j+carry;
            carry = mul/10;
            fct[i].push_back(mul%10);
        }
        while (carry>0){
            fct[i].push_back(carry%10);
            carry /= 10;
        }
    }
}

int main(){
    build();
    // print();
    int n;
    while (cin >>n){
        if (n<0){
            cout <<(n==-1?-1:0) <<endl;
            continue;
        }
        int ans = 0;
        for (int i: fct[n]) ans += i;
        cout <<ans <<endl;
    }
}