#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b){
    return a.first<b.first;
}

int main(){
    int n; cin >>n; getchar(), getchar();
    string tree;
    bool not_first = false;
    while (n--){
        if (not_first) cout <<endl;
        double count = 0;
        map<string,int> m;
        while (getline(cin,tree,'\n') && tree!="") m[tree]++, count++;
        vector<pair<string,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end());
        for (pair<string,int> i: v) cout <<i.first <<" " <<setprecision(4) <<fixed <<i.second/count*100 <<endl;
        not_first = true;
    }
}