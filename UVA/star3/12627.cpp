#include <bits/stdc++.h>

#define ll long long

using namespace std;

int T, K, A, B;
vector<ll> e2{1}, e3{1};

ll dp(int n){
    if (n==0) return 0;
    int ind = -1;
    while (e2[ind+1]<=n) ind++;
    return e3[ind] + 2*dp(n-e2[ind]);
}

ll ans(){
    cin >>K >>A >>B;
    return dp(e2[K]-A+1) - dp(e2[K]-B);
}

int main(){
    for (int i=1;i<=31;i++){
        e2.push_back(e2.back()*2);
        e3.push_back(e3.back()*3);
    }
    cin >>T;
    for (int cs=1;cs<=T;cs++){
        cout <<"Case " <<cs <<": " <<ans() <<endl;
    }
}