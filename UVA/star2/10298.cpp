#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while (cin >>s && s!="."){
        int len = s.size();
        int pre[len];
        for (int i=1,j=pre[0]=-1;i<len;i++){
            while (j>=0 && s[i]!=s[j+1]) j = pre[j];
            if (s[i]==s[j+1]) j++;
            pre[i] = j;
        }
        int ans = len-pre[len-1]-1;
        if (len%ans) cout <<1 <<endl;
        else cout <<len/ans <<endl;
    }
}