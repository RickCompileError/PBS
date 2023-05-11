#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

bool isPrime[2020]{0};

void build_prime(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i=2;i*i<=2020;i++){
        if (!isPrime[i]) continue;
        for (int j=i*i;j<=2020;j+=i) isPrime[j] = 0;
    }
}

int main(){
    string alnum = "";
    for (char i='0';i<='9';i++) alnum += i;
    for (char i='A';i<='Z';i++) alnum += i;
    for (char i='a';i<='z';i++) alnum += i;
    build_prime();
    int T;
    cin >>T;
    string str;
    for (int cs=1;cs<=T;cs++){
        cin >>str;
        int alpha[62]{0};
        for (char i: str) alpha[alnum.find(i)]++;
        string ans = "";
        for (int i=0;i<62;i++) if (isPrime[alpha[i]]) ans += alnum.at(i);
        cout <<"Case " <<cs <<": " <<(ans==""?"empty":ans) <<endl;
    }
}