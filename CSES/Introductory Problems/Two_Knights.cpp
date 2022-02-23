/*
    two knights will attack in every 2*3 or 3*2 block;
    so find the amount of block in current chessboard;
    and each block have two positions causing two knights attacked each other;
    so the answer is Ck2-2*block when k>2;
*/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin >>n;
    for (ll i=1;i<=n;i++){
        ll tot = i*i;
        tot = (tot)*(tot-1)/2;
        cout <<tot-4*(i-1)*(i-2) <<endl;
    }
}