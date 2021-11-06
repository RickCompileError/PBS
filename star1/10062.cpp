#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char,int> a, pair<char,int> b){
    return a.second<b.second || (a.second==b.second && a.first>b.first);
}

int main(){
    string s;
    bool not_first = false;
    while (getline(cin,s,'\n')){
        if (not_first) cout <<endl;
        map<char,int> in;
        for (char i: s) in[i]++;
        vector<pair<char,int>> v(in.begin(),in.end());
        sort(v.begin(), v.end(), cmp);
        for (pair<char,int> i: v) cout <<(int)i.first <<' ' <<i.second <<endl;
        not_first = true;
    }
}