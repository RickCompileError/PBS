#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, ans = 0;
    multiset<int> s;
    cin >>n;
    while (n--){
        cin >>k;
        set<int>::iterator si = s.upper_bound(k);
        if (si!=s.end()) s.erase(si);
        s.insert(k);
    }
    cout <<s.size() <<endl;
}