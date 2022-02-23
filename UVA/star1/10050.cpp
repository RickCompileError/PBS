#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >>n;
        bool day[3651]{false};
        int p; cin >>p;
        while (p--){
            int i; cin >>i;
            for (int j=i;j<=n;j+=i) day[j] = true; 
        }
        for (int j=6;j<=n;j+=7){
            day[j] = false;
            if (j+1<=n) day[j+1] = false;
        }
        int ans = 0;
        for (bool i: day) ans += i;
        cout <<ans <<endl;
    }
}