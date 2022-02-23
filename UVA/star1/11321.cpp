#include <bits/stdc++.h>

using namespace std;

int n, m;

bool cmp(int a, int b){
    if (a%m<b%m) return true;
    if (a%m==b%m){
        if (a%2==0 && b%2==0) return a<b;
        if (abs(a%2)==1 && b%2==0) return true;
        if (a%2==0 && abs(b%2)==1) return false;
        if (abs(a%2)==1 && abs(b%2)==1) return a>b;
    }
    return false;
}

int main(){
    while (cin >>n >>m && n!=0 && m!=0){
        vector<int> v(n);
        for (int i=0;i<n;i++) cin >>v[i];
        sort(v.begin(),v.end(),cmp);
        cout <<n <<' ' <<m <<endl;
        for (int i: v) cout <<i <<endl;
    }
    cout <<0 <<' ' <<0 <<endl;
}