#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >>n;
        bool legal = true;
        int a[n]; cin >>a[0];
        for (int i=1;i<n && legal;i++){
            cin >>a[i];
            legal = !(a[i]%a[0]);
        }
        cout <<(legal?"YES":"NO") <<endl;
    }
}