#include <bits/stdc++.h>

#define time pair<int,int>

using namespace std;

int main(){
    int n, a, b;
    vector<time> v;
    cin >>n;
    while (n--) cin >>a >>b, v.push_back({b,a});
    sort(v.begin(),v.end());
    int end = -1, ans = 0;
    for (time i: v){
        if (i.second>=end){
            ans++;
            end = i.first;
        }
    }
    cout <<ans <<endl;
}