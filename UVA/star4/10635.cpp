/* longest increasing substring problem */
#include <bits/stdc++.h>

using namespace std;

// DP O(n^2) Timeout
void solution1(){
    int t;
    cin >>t;
    for (int cs=1;cs<=t;cs++){
        printf("Case %d: ", cs);
        int n, p, q;
        cin >>n >>p >>q;
        p++, q++;
        int prince_step, princess_step;
        map<int,int> prc_step;
        int prcs_step[q]{0};
        for (int i=1;i<=p;i++) cin >>prince_step, prc_step[prince_step] = i;
        for (int i=0;i<q;i++) cin >>princess_step, prcs_step[i] = prc_step[princess_step];
        int dp[q]{1};
        for (int i=1;i<q;i++){
            for (int j=0;j<i;j++){
                if (prcs_step[i]>prcs_step[j]) dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        cout <<dp[q] <<endl;
    }
}

// DP O(nlogn) Accepted
#define INF 0x3f3f3f3f
void solution2(){
    int t;
    cin >>t;
    for (int cs=1;cs<=t;cs++){
        printf("Case %d: ", cs);
        int n, p, q;
        cin >>n >>p >>q;
        p++, q++;
        int prince_step, princess_step;
        map<int,int> prc_step;
        int prcs_step[q]{0};
        for (int i=1;i<=p;i++) cin >>prince_step, prc_step[prince_step] = i;
        for (int i=0;i<q;i++) cin >>princess_step, prcs_step[i] = prc_step[princess_step];
        vector<int> dp(q+1, INF);
        dp[0] = -INF;
        for (int i=0;i<q;i++){
            if (prcs_step[i]==0) continue;
            int pos = upper_bound(dp.begin(), dp.end(), prcs_step[i]) - dp.begin();
            dp[pos] = prcs_step[i];
        }
        int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin() - 1; // deduct first index
        cout <<ans <<endl;
    }
}

int main(){
    solution2();
}