#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, a, a1 = -1, a2 = -1;
    map<int,int> m;
    cin >>n >>x;
    // this is one method, another can print and return directly when find the combination
    for (int i=1;i<=n;i++){
        cin >>a;
        if (m[x-a]!=0) a1 = m[x-a], a2 = i;
        m[a] = i;
    }
    if (a1==-1) cout <<"IMPOSSIBLE\n";
    else cout <<a1 <<' ' <<a2 <<endl;
}