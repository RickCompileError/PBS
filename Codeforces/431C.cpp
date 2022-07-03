#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mod = 1e9+7;

int main(){
    // k-tree, total weight n, at least one edge of weight at least d
    int n, k, d;
    cin >>n >>k >>d;
    ll acc[n+1]{1}; // no weight restrict
    ll ans[n+1]{0}; // weight restrict
    for (int i=1;i<n+1;i++){
        for (int j=min(k,i);j>=1;j--) acc[i] += acc[i-j];
        for (int j=i-1;j>=max(1, i-k);j--){
            // both weight is less than d
            if (j<d && i-j<d) continue;
            // if leaf weight is over than d, it should plus acc[j]
            else if (i-j>=d) ans[i] += acc[j];
            // if leaf weight is less than d, it should plus ans[j]
            else ans[i] += ans[j];
        }
        // i is one of the paths if itself between d to k
        if (i<=k && i>=d) ans[i]++;
        acc[i] %= mod;
        ans[i] %= mod;
    }
    cout <<ans[n] <<endl;
}