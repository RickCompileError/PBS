#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    if (n==2 || n==3) cout <<"NO SOLUTION\n";
    else{
        int s = (n%2)?1:2;
        for (int i=s;i<=n;i+=2) cout <<i <<' ';
        for (int i=3-s;i<=n;i+=2) cout <<i <<' ';
    }
}