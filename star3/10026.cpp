#include <bits/stdc++.h>

#define ll long long

using namespace std;

typedef struct{
    int id;
    double cost;
} work;

bool cmp(const work& a, const work& b){
    return a.cost<b.cost || (a.cost==b.cost && a.id<b.id);
}

int main(){
    int cs; cin >>cs;
    bool next = false;
    while (cs--){
        if (next) cout <<endl;
        int n, t, f, d = 0; cin >>n;
        vector<work> v;
        for (int i=1;i<=n;i++) cin >>t >>f, v.push_back(work{i,(double)t/f});
        sort(v.begin(),v.end(),cmp);
        cout <<v[0].id;
        for (int i=1;i<v.size();i++) cout <<' ' <<v[i].id;
        cout <<endl;
        next = true;
    }
}