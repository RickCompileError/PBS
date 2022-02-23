#include <bits/stdc++.h>

using namespace std;

array<array<int,100>,100> a;
string s[100];
int m,n;

void dfs(int i, int j){
    if (i<0 || i>=m || j<0 || j>=n || s[i][j]=='*') return;
    s[i][j] = '*';
    dfs(i-1,j-1), dfs(i-1,j), dfs(i-1,j+1);
    dfs(i,j-1), dfs(i,j+1);
    dfs(i+1,j-1), dfs(i+1,j), dfs(i+1,j+1);
}

int main(){
    while (cin >>m >>n && m!=0 && n!=0){
        for (int i=0;i<m;i++) cin >>s[i];
        int ans = 0;
        for (int i=0;i<m;i++) for (int j=0;j<n;j++) if (s[i][j]=='@') dfs(i,j),ans++;
        cout <<ans <<endl;
    }
}