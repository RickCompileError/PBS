#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cs=1;
    while (cin >>n){
        printf("Case #%d: ",cs++);
        int a[n];
        bool legal = true;
        for (int i=0;i<n;i++){
            cin >>a[i];
            if (a[i]<1 || (i>0 && a[i]<=a[i-1])) legal = false;
        }
        set<int> s;
        for (int i=0;i<n && legal;i++){
            for (int j=i;j<n && legal;j++){
                if (s.find(a[i]+a[j])==s.end()) s.insert(a[i]+a[j]);
                else legal = false;
            }
        }
        if (legal) cout <<"It is a B2-Sequence.\n\n";
        else cout <<"It is not a B2-Sequence.\n\n";
    }   
}