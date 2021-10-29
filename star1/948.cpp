#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> v{0,1};

void trans(int i){
    cout <<i <<" = ";
    if (i==0){
        cout <<0 <<" (fib)\n";
        return;
    }
    int sz = v.size()-1;
    while (v[sz]>i) sz--;
    while (i>0){
        if (v[sz]<=i) cout <<1, i -= v[sz];
        else cout <<0;
        sz--;
    }
    while (sz-->=2) cout <<0;
    cout <<" (fib)" <<endl;
}

void build(){
    while (v.back()<1e8) v.push_back(accumulate(v.end()-2,v.end(),0));
}

int main(){
    build();
    int n; cin >>n;
    while (n--){
        int i; cin >>i;
        trans(i);
    }
}