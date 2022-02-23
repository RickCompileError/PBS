#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int m, n; cin >>m >>n;
    string word;
    ll money;
    map<string,ll> table;
    while (m--){
        cin >>word >>money;
        table[word] = money;
    }
    while (n--){
        money = 0;
        while (cin >>word && word!=".") money += table[word];
        cout <<money <<endl;
    }
}