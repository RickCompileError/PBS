#include <bits/stdc++.h>

using namespace std;

int recursive(int n,int k){
    return n==1?1:(recursive(n-1,k)+k-1)%n+1;
}

int main(){
    int n;
    while (cin >>n && n!=0){
        int k=1;
        while (true){
            int ans = (recursive(n,k)-(k-1)+n-1)%n+1;
            if (ans==13){
                cout <<k <<endl;
                break;
            }
            k++;
        }
    }
}