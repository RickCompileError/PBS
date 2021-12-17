#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >>n && n!=0){
        map<string,int> m;
        string str;
        while (n--){
            vector<string> v;
            for (int i=0;i<5;i++) cin >>str, v.push_back(str);
            sort(v.begin(),v.end());
            str = "";
            for (string i: v) str += i;
            m[str]++;
        }
        pair<int,int> ans{0,0};
        for (auto& [k,v]: m){ // feature in c++17
            if (ans.first==0 || ans.first<v) ans = {v,v};
            else if (ans.first==v) ans.second += v;
        }
        cout <<ans.second <<endl;
    }
}