#include <bits/stdc++.h>

#define pr pair<int,int>
#define n1 first
#define n2 second

using namespace std;

const int mxN = 1e4+5, mxK = 1e4+5;
int n, k;
pr customer[mxN], r[mxK];
bool isSet[mxN]{0};
int table[mxK];

int main(){
    cin >>n;
    for (int i=0;i<n;i++) cin >>customer[i].n1 >>customer[i].n2;
    cin >>k;
    for (int i=0;i<k;i++) cin >>r[i].n1, r[i].n2 = i, table[i] = -1;
    sort(r, r+k);
    for (int i=0;i<k;i++){
        for (int j=0;j<n;j++){
            if (isSet[j] || customer[j].n1>r[i].n1) continue;
            if (table[i]==-1 || customer[j].n2>customer[table[i]].n2) table[i] = j;
        }
        if (table[i]!=-1) isSet[table[i]] = true;
    }
    int request = 0, money = 0;
    vector<pr> v;
    for (int i=0;i<k;i++){
        if (table[i]==-1) continue;
        request++;
        money += customer[table[i]].n2;
        v.push_back({table[i]+1,r[i].n2+1});
    }
    cout <<request <<' ' <<money <<endl;
    for (pr i: v) cout <<i.n1 <<' ' <<i.n2 <<endl;
}