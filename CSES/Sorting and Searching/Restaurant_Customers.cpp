#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b;
    cin >>n;
    vector<pair<int,int>> v;
    while (n--) cin >>a >>b, v.push_back({a,1}), v.push_back({b,-1});
    sort(v.begin(),v.end());
    int count = 0, ans = 0;
    for (pair<int,int> i: v){
        count += i.second;
        ans = max(ans,count);
    }
    cout <<ans <<endl;
}