#include <bits/stdc++.h>

using namespace std;

string s[8];
vector<pair<int,int>> v;
int ans = 0;

bool check(){
    pair<int,int> b = v.back();
    if (s[b.first][b.second]=='*') return false;
    for (int i=0;i<v.size()-1;i++){
        if (v[i].first==b.first || v[i].second==b.second ||
            abs(v[i].first-b.first)==abs(v[i].second-b.second)) 
            return false;
    }
    return true;
}

void dfs(int col){
    if (col==8){
        ans++;
        return;
    }
    for (int i=0;i<8;i++){
        v.push_back(make_pair(i,col));
        if (check()) dfs(col+1);
        v.pop_back();
    }
}

void solution1(){
    for (int i=0;i<8;i++) cin >>s[i];
    dfs(0);
    cout <<ans <<endl;
}

int point[8];

bool check2(int col){
    for (int i=0;i<col;i++)
        if (point[i]==point[col] || abs(point[i]-point[col])==col-i) return false;
    return true;
}

void dfs2(int col){
    for (int i=0;i<8;i++){
        if (s[col][i]=='*') continue;
        point[col] = i;
        if (check2(col)){
            if (col==7) ans++;
            else dfs2(col+1);
        }
    }
}

void solution2(){
    for (int i=0;i<8;i++) cin >>s[i];
    dfs2(0);
    cout <<ans <<endl;
}

int main(){
    solution2();
}