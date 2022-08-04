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
#define vpi vector<pi>
#define pb push_back

using namespace std;

void solve(){
    string t; cin >>t;
    int sz = t.size(), n; cin >>n;
    string s[n]; for (int i=0;i<n;i++) cin >>s[i];
    vector<int> dp(sz+1, INF);
    vector<int> which(sz+1, -1);
    vector<int> start(sz+1, -1);
    vector<int> previous(sz+1, -1);
    dp[0] = 0;
    for (int i=0;i<sz;i++){
        for (int j=0;j<n;j++){
            int s_len = s[j].size();
            for (int k=max(i-s_len,0);k<=min(sz-s_len,i);k++){
                string str = t.substr(k, s_len);
                if (str==s[j]){
                    if (dp[i]+1<dp[k+s_len]){
                        dp[k+s_len] = dp[i]+1;
                        which[k+s_len] = j;
                        start[k+s_len] = k;
                        previous[k+s_len] = i;
                    }
                }
            }
        }
    }
    if (dp[sz]==INF) cout <<-1 <<endl;
    else{
        cout <<dp[sz] <<endl;
        int done = sz;
        while (done>0){
            cout <<which[done]+1 <<' ' <<start[done]+1 <<endl;
            done = previous[done];
        }
    }
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}