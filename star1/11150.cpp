#include <bits/stdc++.h>

using namespace std;

void solution1(){
    int n;
    while (cin >>n){
        int drink = n, empty = n;
        while (empty>=3){
            drink += empty/3;
            empty = empty/3+empty%3;
        }
        cout <<drink+(empty==2) <<endl;
    }
}

void solution2(){
    int n;
    while (cin >>n) cout <<n+n/2 <<endl;
}

int main(){
    solution2();
}