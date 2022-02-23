#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >>n; getchar(), getchar();
    string tree;
    bool not_first = false;
    while (n--){
        if (not_first) cout <<endl;
        double count = 0;
        map<string,int> m;
        while (getline(cin,tree,'\n') && tree!="") m[tree]++, count++;
        for (auto& i: m) cout <<i.first <<" " <<setprecision(4) <<fixed <<i.second/count*100 <<endl;
        not_first = true;
    }
}