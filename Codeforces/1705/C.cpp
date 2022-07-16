#include <bits/stdc++.h>

#define ll long long
#define Range pair<ll,ll>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n, c, q;
        string str;
        cin >>n >>c >>q >>str;
        vector<Range> v(c+1,{0,0});
        ll sz[c+1]{(ll)str.size()};
        str = " " + str;
        for (int i=1;i<=c;i++){
            cin >>v[i].first >>v[i].second;
            sz[i] = sz[i-1] + (v[i].second-v[i].first+1);
        }
        ll pos;
        for (int i=0;i<q;i++){
            cin >>pos;
            int dv = 0;
            while (pos>sz[dv]) dv++;
            while (dv>0){
                if (pos>sz[dv-1]) pos = v[dv].first+(pos-sz[dv-1]-1);
                dv--;
            }
            cout <<str[pos] <<endl;
        }
    }
}