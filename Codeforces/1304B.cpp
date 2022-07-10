#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >>n >>m;
    string str, rstr, left, mid, right;
    left = mid = right = "";
    map<string,int> mp;
    for (int i=0;i<n;i++){
        cin >>str, rstr = str;
        reverse(rstr.begin(), rstr.end());
        mp[str]++;
        if (str==rstr && str.size()>mid.size()) mid = str;
        else if (str!=rstr && mp[rstr]==1){
            left = left + str;
            right = rstr + right;
        }
    }
    cout <<(left+mid+right).size() <<endl;
    cout <<left+mid+right <<endl;
}