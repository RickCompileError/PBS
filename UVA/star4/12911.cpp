#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxN = 40;

int main(){
    int N;
    ll T;
    while (cin >>N >>T){
        // split into two subsets because 2^40 will timeout
        int lsize, rsize;
        if ((lsize=N/2)==0) lsize = 1, rsize = N - lsize;
        ll s[mxN+1];
        for (int i=1;i<=N;i++) cin >>s[i];
        map<ll,int> lcount, rcount;
        // use bit to represent the choosing index in left subset
        for (int i=1;i<(1<<lsize);i++){
            ll sum = 0;
            for (int j=0;j<lsize;j++) if ((i&1<<j) != 0) sum += s[j];
            lcount[sum]++;
        }
        // use bit to represent the choosing index in right subset
        for (int i=1;i<(1<<rsize);i++){
            ll sum = 0;
            for (int j=0;j<rsize;j++) if ((i&1<<j) != 0) sum += s[lsize+j];
            rcount[sum]++;
        }
        ll ans = 0;
        for (pair<ll,int> i: lcount) ans += i.second * rcount[T-i.first];
        cout <<ans+lcount[T]+rcount[T] <<endl;
    }
}