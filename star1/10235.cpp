#include <bits/stdc++.h>

using namespace std;

bool prime(int n){
    for (int i=2;i*i<=n;i++) if (n%i==0) return false;
    return true;
}

int main(){
    int n;
    while (cin >>n){
        cout <<n;
        if (prime(n)){
            int serve = n, tmp = n%10;
            n /= 10;
            while (n>0){
                tmp *= 10;
                tmp += n%10;
                n /= 10;
            }
            if (serve!=tmp && prime(tmp)) cout <<" is emirp.\n";
            else cout <<" is prime.\n";
        }
        else cout <<" is not prime.\n";
    }
}