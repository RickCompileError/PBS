#include <bits/stdc++.h>

using namespace std;

void solution1(){
    int n, m, h, t;
    map<int,int,greater<int>> price;
    cin >>n >>m;
    while (n--) cin >>h, price[h]++;
    while (m--){
        cin >>t;
        auto i = price.lower_bound(t);
        if (i == price.end()) cout <<-1 <<endl;
        else{
            cout <<i->first <<endl;
            if (i->second==1) price.erase(i);
            else i->second--;
        }
    }
}

void solution2(){
    int n, m, h, t;
    set<pair<int,int>> s;
    cin >>n >>m;
    for (int i=0;i<n;i++) cin >>h, s.insert({h,i});
    while (m--){
        cin >>t;
        auto i = s.lower_bound({t+1,0}); // find the minimum value that is greater than t
        // i == s.begin() means that there is no value less or equals t, because s.begin() is the minimum value
        if (i==s.begin()) cout <<-1 <<endl;
        else{
            i--;
            cout <<i->first <<endl;
            s.erase(i);
        }
    }
}

int main(){
    solution2();
}