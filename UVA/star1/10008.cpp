#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char,int> a, pair<char,int> b){
    return a.second>b.second || (a.second==b.second && a.first<b.first);
}

int main(){
    int n; cin >>n; getchar();
    map<char,int> m;
    while (n--){
        string s;
        getline(cin,s,'\n');
        for (char i: s){
            i = toupper(i);
            if (i>='A' && i<='Z') m[i]++;
        }
    }
    vector<pair<char,int>> v;
    for (auto i: m) v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    for (pair<char,int> i: v) cout <<i.first <<' ' <<i.second <<endl;
}