#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int sz = 1e5+1;
vector<int> prime;
vector<int> psum;

int sum(ll n){
    int s = 0;
    while (n>0){
        s += n%10;
        n /= 10;
    }
    return s;
}

void build(){
    bool number[sz]{1,1};
    for (int i=2;i*i<sz;i++){
        if (number[i]) continue;
        for (int j=i*i;j<sz;j+=i) number[j] = true;
    }
    for (int i=2;i<sz;i++) if (!number[i]) prime.push_back(i), psum.push_back(sum(i));
}

bool check(ll n){
    for (int i: prime) if (i==n) return false;
    ll tmp = n;
    int s1 = 0, s2 = sum(n);
    for (int i=0;n>1 && i<prime.size() && prime[i]<=n;){
        while (n%prime[i]==0){
            s1 += psum[i];
            n /= prime[i];
        }
        i++;
    }
    if (tmp==n) return false; // n after for loop doesn't change (means n is prime)
    if (n>1) s1 += sum(n); // deal with the situation that n is divided but still a prime
    return s1==s2;
}

int main(){
    build();
    ll cs, n; cin >>cs;
    while (cs--){
        cin >>n;
        for (ll i=n+1;;i++){
            if (check(i)){
                cout <<i <<endl;
                break;
            }
        }
    }
}