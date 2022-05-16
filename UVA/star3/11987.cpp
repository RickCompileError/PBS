#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxn = 1e5+1;
int root[mxn];
vector<int> s[mxn];

void union_set(int x, int y){
    x = root[x];
    y = root[y];
    if (x==y) return;
    if (s[x].size()<s[y].size()) swap(x,y); // always x bigger
    for (int i: s[y]) s[x].push_back(i), root[i] = x;
    s[y].clear();
}

void method2(){
    int n, m, t, p, q;
    while (cin >>n >>m){
        for (int i=1;i<mxn;i++) root[i] = i, s[i] = vector<int>{i};
        while (m--){
            cin >>t;
            if (t==1){
                cin >>p >>q;
                union_set(p,q);
            }else if (t==2){
                cin >>p >>q;
                int rtp = root[p], rtq = root[q];
                vector<int>::iterator it = s[rtp].begin();
                while (*it!=p) it++;
                s[rtp].erase(it), s[rtq].push_back(p);
                root[p] = rtq;
            }else{
                cin >>p;
                cout <<s[root[p]].size() <<' ' <<accumulate(s[root[p]].begin(), s[root[p]].end(), (ll)0) <<endl;
            }
        }
    }
}

int main(){
    method2();
}