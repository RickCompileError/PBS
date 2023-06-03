#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;
int dp[mxN+1]{};

int find(int i){
    int mx = 0;
    while (i>0){
        mx = max(mx, i%10);
        i /= 10;
    }
    return mx;
}

// 20ms
void solution1(){
    int n;
    cin >>n;
    for (int i=1;i<=n;i++){
        dp[i] = dp[i-find(i)] + 1;
    }
    cout <<dp[n] <<endl;
}

// 10ms
void solution2(){
    int n, tmp, mx, ans = 0;
    cin >>n;
    while (n){
        mx = 0;
        tmp = n;
        while (tmp>0){
            mx = max(mx, tmp%10);
            tmp /= 10;
        }
        ans++, n -= mx;
    }
    cout <<ans;
}

int main(){
    solution2();
}
