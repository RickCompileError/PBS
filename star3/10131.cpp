#include <bits/stdc++.h>

#define elephant array<int,3> // 0 for id, 1 for weight, 2 for IQ

using namespace std;

bool cmp(elephant a, elephant b){
    return (a[1]<b[1]) || (a[1]==b[1] && a[2]>b[2]);
}

void solution1(){
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

void dfs(vector<elephant>& ve, vector<int>& vi, int ind){
    if (vi[ind]!=-1) dfs(ve,vi,vi[ind]);
    cout <<ve[ind][0] <<endl;
}

void solution2(){
    vector<elephant> v;
    int id = 1, w, s;
    while (cin >>w >>s) v.push_back({id++,w,s});
    sort(v.begin(),v.end(),cmp);
    vector<int> len(v.size(),1);
    vector<int> pre(v.size(),-1);
    int max_length = 0;
    int max_index = -1;
    for (int i=0;i<v.size();i++){
        for (int j=i+1;j<v.size();j++){
            if (v[i][1]<v[j][1] && v[i][2]>v[j][2]){
                if (len[i]+1>len[j]){
                    len[j] = len[i] + 1;
                    pre[j] = i;
                }
            }
        }
        if (len[i]>max_length){
            max_length = len[i];
            max_index = i;
        }
    }
    cout <<max_length <<endl;
    dfs(v,pre,max_index);
}

int main(){
    solution2();
}