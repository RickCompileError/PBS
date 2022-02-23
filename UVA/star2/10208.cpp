#include <bits/stdc++.h>

using namespace std;

const int mxp = 5e6;
vector<int> prime;

void build(){
    bool p[mxp]{0};
    p[0] = p[1] = 1;
    for (int i=2;i*i<mxp;i++){
       if (p[i]) continue;
       for (int j=i*i;j<mxp;j+=i) p[j] = 1; 
    }
    for (int i=2;i<mxp;i++) if (!p[i]) prime.push_back(i);
}

void factor(int i){
    if (i==0) return;
    while (i%2==0) i /= 2;
    for (int j: prime){
        while (i%j==0) i /= j;
    }
}

int main(){
    for (int i=4;i<=1e7;i++) factor(i);
    cout <<"done\n";
}