#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >>n;
    cout <<(n%2?'7':'1'); 
    for (int i=0,sz=(n-2)/2;i<sz;i++) cout <<'1';
    cout <<endl;
}