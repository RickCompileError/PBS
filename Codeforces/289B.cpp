#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, d, t;
    cin >>n >>m >>d;
    t = n*m;
    vector<int> v(t,0);
    for (int i=0;i<t;i++) cin >>v[i];
    sort(v.begin(), v.end());
    for (int i=0, j=v[t/2];i<t;i++) v[i] -= j;
    bool legal = true;
    for (int i=0;i<t && legal;i++){
        if (v[i]%d) legal = false;
        v[i] /= d;
    }
    if (legal){
        int ans = 0;
        for (int i=0;i<t;i++) ans += abs(v[i]);
        cout <<ans <<endl;
    }
    else cout <<-1 <<endl;
}