#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxN = 4e3+5;
vector<int> node[mxN];
ll tot[mxN];
string color;

void dfs(int cur=1){
    tot[cur] += color[cur-1];
    for (int i: node[cur]){
        dfs(i);
        tot[cur] += tot[i];
    }
}

int main(){
    int t; cin >>t;
    while (t--){
        for (int i=0;i<mxN;i++) node[i].clear();
        memset(tot, 0, sizeof(tot));
        int amt, parent; cin >>amt;
        for (int i=2;i<=amt;i++) cin >>parent, node[parent].push_back(i);
        cin >>color;
        for (int i=0;i<color.size();i++) color[i] = (color[i]=='B'?1:-1);
        dfs();
        int ans = 0;
        for (int i=1;i<=amt;i++) if (tot[i]==0) ans++;
        cout <<ans <<endl;
    }
}