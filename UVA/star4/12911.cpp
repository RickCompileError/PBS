#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxN = 40;

int main(){
    int N, lsize, rsize;
    ll T, s[mxN+1];
    while (cin >>N >>T){
        memset(s,0,sizeof(s));
        if ((lsize=N/2)==0) lsize = 1;
        rsize = N - lsize;
        for (int i=1;i<=N;i++) cin >>s[i];
        map<ll,int> lcount, rcount;
        for (int i=1;i<(1<<lsize);i++){
            ll sum = 0;
            for (int j=1;j<=lsize;j++){
                if ((i&(1<<j-1)) != 0) sum += s[j];
            }
            lcount[sum]++;
        }
        for (int i=1;i<(1<<rsize);i++){
            ll sum = 0;
            for (int j=1;j<=rsize;j++){
                if ((i&(1<<j-1)) != 0) sum += s[lsize+j];
            }
            rcount[sum]++;
        }
        ll ans = 0;
        for (map<ll,int>::iterator i=lcount.begin();i!=lcount.end();i++){
            ans += i->second*rcount[T-i->first];
        }
        cout <<ans+lcount[T]+rcount[T] <<endl;
    }
}