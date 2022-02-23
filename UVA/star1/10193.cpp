#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n; cin >>n;
    for (int i=1;i<=n;i++){
        printf("Pair #%d: ",i);
        string s1, s2; cin >>s1 >>s2;
        bitset<32> b1(s1), b2(s2);
        int t1 = b1.to_ulong(), t2 = b2.to_ulong();
        if (gcd(t1,t2)<=1) cout <<"Love is not all you need!\n";
        else cout <<"All you need is love!\n";
    }
}