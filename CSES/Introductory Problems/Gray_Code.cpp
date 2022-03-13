#include <bits/stdc++.h>

using namespace std;

int n;

void print(vector<string> ans){
    for (string i: ans) cout <<i <<endl;
}

vector<string> recur(int n){
    if (n==1) return {"0","1"};
    vector<string> tmp = recur(n-1);
    vector<string> ext;
    for (int i=0;i<tmp.size();i++) ext.push_back("0"+tmp[i]);
    for (int i=tmp.size()-1;i>=0;i--) ext.push_back("1"+tmp[i]);
    return ext;
}

int main(){
    cin >>n;
    print(recur(n));
}

/* 
000
001
011
010
110
111
101
100 */