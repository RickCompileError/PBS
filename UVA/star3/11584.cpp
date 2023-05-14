#include <bits/stdc++.h>

using namespace std;

bool if_pl(string str, int j, int i){
    for (;i>=j;i--,j++) if (str[j]!=str[i]) return false;
    return true;
}

int main(){
    int n;
    cin >>n;
    while (n--){
        string str;
        cin >>str;
        int sz = str.size();
        vector<int> dp(sz+1, 0);
        dp[1] = 1;
        for (int i=2;i<=sz;i++){
            dp[i] = dp[i-1] + 1;
            for (int j=0;j<i;j++){
                if (if_pl(str, j, i-1)) dp[i] = min(dp[j]+1, dp[i]);
            }
        }
        cout <<dp[sz] <<endl;
    }
}