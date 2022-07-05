#include <bits/stdc++.h>

using namespace std;

bool dp(int n, int div){
    if (div>n) return false;
    if (dp(n, div*10+4) || dp(n, div*10+7)) return true;
    return n%div==0;
}

int main(){
    int n; cin >>n;
    cout <<(dp(n,4)||dp(n,7)?"YES":"NO") <<endl;
}