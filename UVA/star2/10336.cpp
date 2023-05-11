#include <bits/stdc++.h>

using namespace std;

int n, h, w;

void dfs(vector<string> str, vector<vector<bool>> &state, int x, int y, char c){
    if (str[x][y]!=c || state[x][y]) return;
    state[x][y] = 1;
    if (x-1>=0) dfs(str, state, x-1, y, c);
    if (x+1<h) dfs(str, state, x+1, y, c);
    if (y-1>=0) dfs(str, state, x, y-1, c);
    if (y+1<w) dfs(str, state, x, y+1, c);
}

bool cmp(pair<char, int> &a, pair<char,int> &b){
    return a.second>b.second || (a.second==b.second && a.first<b.first);
}

int main(){
    cin >>n;
    for (int cs=1;cs<=n;cs++){
        cin >>h >>w;
        vector<pair<char, int>> ans;
        for (int i=0;i<26;i++) ans.push_back({'a'+i, 0});
        vector<string> str;
        string s;
        vector<vector<bool>> state(h, vector<bool>(w, 0));
        for (int i=0;i<h;i++) cin >>s, str.push_back(s);
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                if (state[i][j]) continue;
                dfs(str, state, i, j, str[i][j]);
                ans[str[i][j]-97].second++;
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("World #%d\n", cs);
        for (pair<char,int> i: ans) if (i.second!=0) cout <<i.first <<": " <<i.second <<endl;
    }
}