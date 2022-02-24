/* 
    Reference from GeeksforGeeks: Count total set bits in all numbers from 1 to n
 */
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll base = 1;

// Method 3 (can't understand)
void solution1(){
    ll n, ans = 0;
    cin >>n;
    n++; 
    for (int i=60;i>=0;i--){
        ans += n/(base<<(i+1))*(base<<i); // count the appearance times of 1 at index i
        ans += max((ll)0,n%(base<<(i+1))-(base<<i)); 
    }
    cout <<ans <<endl;
}

ll count(ll x){
    return x*pow(2,x-1);
}

ll countAllOne(ll n){
    if (n<=1) return n;
    ll mxbits = 0;
    while ((base<<mxbits)<=n) mxbits++;
    mxbits--;
    return count(mxbits) + (n%(base<<mxbits)+1) + countAllOne(n%(base<<mxbits));
}

// Method 4
void solution2(){
    ll n;
    cin >>n;
    cout <<countAllOne(n) <<endl;
}

int main(){
    solution2();
}
/* 
    1 bits = 1
    2 bits = 10 11
    3 bits = 100 101 110 111
    4 bits = 1000 1001 1010 1011 1100 1101 1110 1111
 */