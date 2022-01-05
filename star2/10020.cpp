#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs, m, l, r; cin >>cs;
    bool first = true;
    while (cs--){
        if (!first) cout <<endl;
        cin >>m;
        vector<pair<int,int>> v;
        while (cin >>l >>r && (l || r)) v.push_back({l,r});
        sort(v.begin(),v.end());
        int bound = 0, i = 0;
        bool legal = true;
        vector<int> ans;
        while (bound<m){
            int mx = -1;
            while (i<v.size() && v[i].first<=bound){
                if (v[i].second<=bound){
                    i++;
                    continue;
                }
                if (mx==-1 || v[mx].second-bound<v[i].second-bound) mx = i;
                i++;
            }
            if (mx==-1){
                legal = false;
                break;
            }
            ans.push_back(mx);
            bound = v[mx].second;
        }
        if (legal){
            cout <<ans.size() <<endl;
            for (int i: ans) cout <<v[i].first <<' ' <<v[i].second <<endl;
        }
        else cout <<0 <<endl;
        first = false;
    }
}