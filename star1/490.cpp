#include <bits/stdc++.h>

using namespace std;

void solution(){
    int mxlen = 0;
    string s;
    vector<string> v;
    while (getline(cin,s,'\n')){
        mxlen = max(mxlen,(int)s.size());
        v.push_back(s);
    }
    vector<string> ans;
    for (int i=0;i<mxlen;i++){
        string s1 = "";
        for (int j=v.size()-1;j>=0;j--){
            if (v[j].size()<=i) s1 += " ";
            else s1 += v[j][i];
        }
        ans.push_back(s1);
    }
    for (int i=0;i<ans.size();i++) cout <<ans[i] <<endl;
}

void another(){
    int n = 0, mxlen = 0;
    string str[100];
    while (getline(cin,str[n],'\n')) mxlen = max(mxlen,(int)str[n].size()), n++;
    for (int i=0;i<mxlen;i++){
        for (int j=n-1;j>=0;j--){
            if (str[j].size()<=i) cout <<' ';
            else cout <<str[j][i];
        }
        cout <<endl;
    }
}

int main(){
    solution();
}