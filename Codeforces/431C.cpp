#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mod = 1e9+7;

void method2(){
    int n, k, d;
    cin >>n >>k >>d;
    ll s[n+1][2];
    memset(s, 0, sizeof(s));
    s[0][0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i&&j<=k;j++){
            if (j>=d){
                s[i][1] += s[i-j][0] + s[i-j][1];
            }else{
                s[i][0] += s[i-j][0];
                s[i][1] += s[i-j][1];
            }
            s[i][0] %= mod;
            s[i][1] %= mod;
        }
    }
    cout <<s[n][1] <<endl;
}

void method1(){
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

int main(){
    method2();
}