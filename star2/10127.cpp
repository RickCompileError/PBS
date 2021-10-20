#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n;
    while (cin >>n){
        int count = 1, div = 1;
        while (div%n){
            div %= n;
            div = div*10+1;
            count++;
        }
        cout <<count <<endl;
    }
}