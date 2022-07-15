#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main(){
    ll n; cin >>n;
    if (n%2==0) cout <<"NO" <<endl;
    else{
        cout <<"YES" <<endl;
        for (int i=0,sz=2*n;i<sz;i++) cout <<(i%n)*2+(i&1)+1 <<' ';
    }
}

/*
 * According to the condition that S(i) = a(i)+...+a(i+n-1), for all 1<=k,m<=n+1, k!=m, |S(k) - S(m)| <= 1
 * We can know that S(i) - S(i+1) = [a(i)+...+a(i+n-1)] - [a(i+1)+...+a(i+n)] = |a(i) - a(i+n)| <= 1,
 * because all number must be different, |a(i) - a(i+n)| = 1.
 * It is clear from this that (a(i)-a(i+n)) and (a(i+1)-a(i+n+1)) have opposite signs. (based on condition)
 * The problem is how to simulate it.
 * Condition:
 * (1) |a(i) - a(i+n)| = 1
 * (2) [a(i) - a(i+n)] = -[a(i+1) - a(i+n+1)]
 * Solution:
 * (1) (i%n)*2
 * (2) (i&1)
 */