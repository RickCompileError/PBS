#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    while (cin >>n >>m){
        vector<int> ans{n};
        while (m!=0 && n%m==0 && n!=n/m) ans.push_back(n/m), n /= m;
        if (ans.back()==1 && ans.size()>1) for (int i=0;i<ans.size();i++) cout <<ans[i] <<(i+1==ans.size()?"\n":" ");
        else cout <<"Boring!\n";
    }
}