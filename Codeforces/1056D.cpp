#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+1;
vector<int> v[mxN];
int ans[mxN]{0};

void dfs(int cur=1, int prev=0){
    if (v[cur].size()==0){
        ans[cur]++;
    }else{
        for (int i: v[cur]) dfs(i, cur);
    }
    ans[prev] += ans[cur];
}

void method2(){
    int n, p; cin >>n;
    for (int i=2;i<=n;i++) cin >>p, v[p].push_back(i);
    dfs();
    sort(ans+1, ans+n+1);
    for (int i=1;i<=n;i++) cout <<ans[i] <<(i==n?'\n':' ');
}

// time out
void method1(){
    int n; cin >>n;
    int p[n+1]{0};
    int ans[n+1]{0};
    bool isParent[n+1]{0,1};
    for (int i=2;i<=n;i++) cin >>p[i], isParent[p[i]] = true;
    for (int i=1;i<=n;i++){
        if (isParent[i]) continue;
        ans[i]++;
        while (p[i]!=0){
            ans[p[i]]++;
            p[i] = p[p[i]];
        }
    }
    sort(ans+1, ans+n+1);
    for (int i=1;i<=n;i++) cout <<ans[i] <<(i==n?'\n':' ');
}

int main(){
    method2();
}