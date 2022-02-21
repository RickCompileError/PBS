#include <bits/stdc++.h>

#define elephant array<int,3>

using namespace std;

const int mx=1e3+5;

bool cmp(elephant a, elephant b){
    return (a[1]<b[1]) || (a[1]==b[1] && a[2]>b[2]);
}

int main(){
    vector<elephant> v;
    int id = 1, w, s;
    while (cin >>w >>s) v.push_back({id++,w,s});
    sort(v.begin(),v.end(),cmp);
    pair<int,int> ans[v.size()]; // first for length, second for point to
    for (int i=v.size()-1;i>=0;i--){
        ans[i] = {1,-1};
        int len = 0;
        for (int j=i+1;j<v.size();j++){
            if (v[i][1]<v[j][1] && v[i][2]>v[j][2] &&
                (ans[i].second==-1 || ans[j].first>ans[ans[i].second].first)) ans[i].second = j;
        }
        if (ans[i].second!=-1) ans[i].first += ans[ans[i].second].first;
    }
    int mxa = 0;
    for (int i=0;i<v.size();i++){
        if (ans[i].first>ans[mxa].first) mxa = i;
    }
    cout <<ans[mxa].first <<endl;
    do{
        cout <<v[mxa][0] <<endl;
        mxa = ans[mxa].second;
    } while (mxa!=-1);
}