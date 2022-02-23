#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e2+5;
vector<int> v[mxN];
int color[mxN];

bool bfs(int cur, int val, int prev=-1){
    color[cur] = val;
    for (int i: v[cur]){
        if (i==prev || color[i]==(!val)) continue;
        if (color[i]==val || !bfs(i,!val,cur)) return false;
    }
    return true;
}

int main(){
    int n, l, n1, n2;
    while (cin >>n && n){
        cin >>l;
        for (int i=0;i<mxN;i++) v[i].clear();
        memset(color,2,sizeof(color));
        while (l--){
            cin >>n1 >>n2;
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        if (bfs(n1,0)) cout <<"BICOLORABLE.\n";
        else cout <<"NOT BICOLORABLE.\n";
    }
}