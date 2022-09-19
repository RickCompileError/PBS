#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define pll pair<ll,ll>
#define e1 first
#define e2 second
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back
#define rep(i, l, r) for (int i=l;i<=r;i++)
#define repn(i, l, r) for (int i=l;i<r;i++)

using namespace std;

int cmp(char a, char b){
    return a<b?1:(a>b?-1:0);
}

// Zero-sum game
// Alice choose one and Bob will choose the best he can.
void solve(){
    string str; cin >>str;
    int sz = str.size();
    int dp[sz+1][sz+1];
    memset(dp, 0, sizeof(dp));
    for (int i=2;i<=sz;i+=2){
        for (int l=0;l+i<=sz;l++){
            int r = l + i;
            dp[l][r] = -1;
            // Alice choose l and Bob choose (l+1 or r-1)
            {
                int res = 1;
                if (dp[l+1][r-1]!=0) res = min(res, dp[l+1][r-1]);
                else res = min(res, cmp(str[l], str[r-1]));
                if (dp[l+2][r]!=0) res = min(res, dp[l+2][r]);
                else res = min(res, cmp(str[l], str[l+1]));
                dp[l][r] = max(dp[l][r], res);
            }
            // Alice choose r-1 and Bob choose (l or r-2)
            {
                int res = 1;
                if (dp[l+1][r-1]!=0) res = min(res, dp[l+1][r-1]);
                else res = min(res, cmp(str[r-1], str[l]));
                if (dp[l][r-2]!=0) res = min(res, dp[l][r-2]);
                else res = min(res, cmp(str[r-1], str[r-2]));
                dp[l][r] = max(dp[l][r], res);
            }
        }
    }
    cout <<(dp[0][sz]==0?"Draw":(dp[0][sz]>0?"Alice":"Bob")) <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}