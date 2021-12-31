#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return (b==0?a:gcd(b,a%b));
}

int main(){
    int num;
    while (cin >>num && num!=0){
        vector<int> n, d;
        do{
            n.push_back(num);
        } while (cin >>num && num!=0);
        sort(n.begin(),n.end());
        for (int i=1;i<n.size();i++) d.push_back(n[i]-n[i-1]);
        int mx = d[0];
        for (int i=1;i<d.size();i++) mx = gcd(mx,d[i]);
        cout <<mx <<endl;
    }
}