#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, start = 1, ans = 0;
    map<int,int> m;
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>k;
        if (m[k]==0){
            m[k] = i;
        }else{
            if (m[k]>=start) start = m[k] + 1;
            m[k] = i;
        }
        ans = max(ans,i-start+1);
    }
    cout <<ans <<endl;
}