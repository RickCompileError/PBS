#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        string str; cin >>str;
        int cur = -1;
        bool legal = true;
        for (int i=1;i<str.size() && legal;i++){
            if (str[i]==str[i-1]){
                if (cur==-1) cur = str[i] - '0';
                else if (cur==0 && str[i]=='1') cur = 1;
                else if (cur==1 && str[i]=='0') legal = false;
            }
        }
        cout <<(legal?"YES":"NO") <<endl;
    }
}