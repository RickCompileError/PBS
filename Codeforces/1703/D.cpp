#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >>n;
        set<string> s;
        bool ans[n]{0};
        string str[n];
        string left, right;
        for (int i=0;i<n;i++) cin >>str[i], s.insert(str[i]);
        for (int i=0;i<n;i++){
            for (int j=1, sz = str[i].size();j<sz;j++){
                left = str[i].substr(0,j);
                right = str[i].substr(j,sz-j);
                if (s.find(left)!=s.end() && s.find(right)!=s.end()) ans[i] = true;
            }
        }
        for (int i=0;i<n;i++) cout <<ans[i];
        cout <<endl;
    }
}