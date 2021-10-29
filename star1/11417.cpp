#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n;
    while (cin >>n && n!=0){
        int g = 0;
        for (int i=1;i<n;i++)
            for (int j=i+1;j<=n;j++)
                g += gcd(i,j);
        cout <<g <<endl;
    }
}