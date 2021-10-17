#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >>n;
    while (n--){
        int l, ans=0; cin >>l;
        int t[l];
        for (int i=0;i<l;i++) cin >>t[i];
        for (int i=0;i<l;i++)
            for (int j=l-1;j>i;j--)
                if (t[j]<t[j-1]) swap(t[j],t[j-1]), ans++;
        cout <<"Optimal train swapping takes " <<ans <<" swaps.\n";
    }
}