#include <bits/stdc++.h>

using namespace std;

int main(){
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