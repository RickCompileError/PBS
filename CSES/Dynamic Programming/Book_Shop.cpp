#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int mxN = 1e3, mxX = 1e5;
int h[mxN+1], s[mxN+1], dp[mxN+1][mxX+1]{{}};
pair<int,int> hs[mxN+1];
vector<pair<int,int>> dp1[mxN+1];

// runtime error, it may cuase out of memory because the code saves the datas that have same price in different combinations
void solution1(){
    int n, x, ans = 0;
    cin >>n >>x;
    for (int i=0;i<n;i++) cin >>h[i];
    for (int i=0;i<n;i++) cin >>s[i];
    dp1[0].pb({0,0});
    for (int i=0;i<n;i++){
        for (auto &j: dp1[i]){
            dp1[i+1].pb(j);
            if (j.first+h[i]<=x) dp1[i+1].pb({j.first+h[i], j.second+s[i]});
        }
    }
    for (auto &i: dp1[n]) ans = max(ans, i.second);
    cout <<ans <<endl;
}

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return (a.first==b.first?a.second>b.second:a.first<b.first);
}

// a 0-1 knapsack problem
void solution2(){
    int n, x;
    cin >>n >>x;
    for (int i=1;i<=n;i++) cin >>hs[i].first;
    for (int i=1;i<=n;i++) cin >>hs[i].second;
    sort(hs+1, hs+n+1);
    for (int i=1;i<=n;i++){
        for (int j=0;j<=x;j++){
            if (j>=hs[i].first) dp[i][j] = max(dp[i-1][j], dp[i-1][j-hs[i].first]+hs[i].second);
            // if (j-hs[i].first==0 || dp[i-1][j-hs[i].first]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-hs[i].first]+hs[i].second);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout <<dp[n][x];
}

// simplified
void solution3(){
    int n, x;
    cin >>n >>x;
    int dp[x+1]{};
    for (int i=0;i<n;i++) cin >>h[i];
    for (int i=0;i<n;i++) cin >>s[i];
    for (int i=0;i<n;i++){
        for (int j=x;j>=h[i];j--){
            dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }
    cout <<dp[x] <<endl;
}

int main(){
    solution3();
}