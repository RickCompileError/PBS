#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int len; cin >>len;
        string str; cin >>str;
        int last_update = -1;
        for (int i=0;i<len;i++){
            if (str[i]!='?'){
                last_update = i;
                int j = i-1;
                while (j>=0 && str[j]=='?') str[j] = (str[j+1]=='B'?'R':'B'), j--;
            }
        }
        if (last_update!=len-1){
            for (int i=last_update+1;i<len;i++) str[i] = (str[i-1]=='B'?'R':'B');
        }
        cout <<str <<endl;
    }
}