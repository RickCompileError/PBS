#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >>n){
        if (n<1 || n>3000){
            cout <<"Not jolly\n";
            continue;
        }
        int seq[n];
        bool exist[n]{0};
        bool legal = true;
        for (int i=0;i<n;i++){
            cin >>seq[i];
            if (i==0) continue;
            int dif = abs(seq[i]-seq[i-1]);
            if (n<=0 || dif>n-1 || dif==0 || exist[dif]) legal = false;
            else exist[dif] = true;
        }
        if (legal) cout <<"Jolly\n";
        else cout <<"Not jolly\n";
    }
}