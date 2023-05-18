#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<int> prime;

void build_prime(){
    bool p[101];
    fill_n(p, 101, true);
    p[0] = p[1] = false;
    for (int i=2;i*i<=100;i++){
        if (!p[i]) continue;
        for (int j=i*i;j<=100;j+=i) p[j] = false;
    }
    for (int i=2;i<=100;i++) if (p[i]) prime.pb(i);
}

vector<int> ans[101];

void build_answer(){
    for (int i=2;i<=100;i++){
        ans[i] = ans[i-1];
        int tmp = i;
        for (int j=0;j<prime.size() && tmp>1;j++){
            if (tmp%prime[j]) continue;
            if (j+1>ans[i].size()) ans[i].pb(0);
            while (tmp%prime[j]==0) ans[i][j]++, tmp/=prime[j];
        }
    }
}

int main(){
    build_prime();
    build_answer();
    int n;
    while (cin >>n && n!=0){
        printf("%3d! =", n);
        for (int i=0;i<ans[n].size();i++){
            if (i!=0 && i%15==0) printf("\n      ");
            printf("%3d", ans[n][i]);
        }
        printf("\n");
    }
}