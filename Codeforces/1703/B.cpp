#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t, n; cin >>t;
    while (t--){
        cin >>n;
        string str; cin >>str;
        int ans = 0;
        map<char, bool> m;
        for (char i: str){
            if (m[i]) ans++;
            else ans += 2, m[i] = true;
        }
        cout <<ans <<endl;
    }

}