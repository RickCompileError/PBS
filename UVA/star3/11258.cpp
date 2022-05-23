#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int N;
    cin >>N;
    while (N--){
        string str;
        cin >>str;
        ll ans[str.size()+1]{0};
        for (int i=str.size()-1;i>=0;i--){
            for (int j=1;j<=10 && i+j<=str.size();j++){
                string s = str.substr(i,j);
                ll num = stoll(s);
                if (num>INT_MAX) break;
                ans[i] = max(ans[i],num+ans[i+j]);
            }
        }
        cout <<ans[0] <<endl;
    }
}