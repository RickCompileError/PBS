#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t, n; cin >>t;
    while (t--){
        cin >>n;
        int after[n];
        for (int i=0;i<n;i++) cin >>after[i];
        for (int i=0;i<n;i++){
            int op; cin >>op; getchar();
            for (int j=0;j<op;j++){
                if (getchar()=='D') after[i]++;
                else after[i]--;
                after[i] = (after[i]+10) % 10;
            }
        }
        for (int i=0;i<n;i++) cout <<after[i] <<(i==n-1?"\n":" ");
    }
}