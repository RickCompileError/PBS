#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int LOG = 30;

int main(){
    int t; cin >>t;
    while (t--){
        ll n, k; cin >>n >>k;
        ll a[n]; for (int i=0;i<n;i++) cin >>a[i];
        vector<vector<ll>> dp(LOG+1, vector<ll>(n+1,LONG_LONG_MIN));
        dp[0][0] = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<=LOG;j++){
                if (dp[j][i]!=LONG_LONG_MIN){
                    dp[j][i+1] = max(dp[j][i+1], dp[j][i]-k+(a[i]>>j));
                    int k = min(j+1,LOG);
                    dp[k][i+1] = max(dp[k][i+1], dp[j][i]+(a[i]>>k));
                }
            }
        }
        ll ans = LONG_LONG_MIN;
        for (int j=0;j<LOG+1;j++) ans = max(ans, dp[j][n]);
        cout <<ans <<endl;
    }
}