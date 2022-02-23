#include <bits/stdc++.h>

using namespace std;

bool func[10001]{false};
vector<int> prime;

void build_prime(){
    vector<bool> p(10001,true);
    p[0] = p[1] = false;
    for (int i=2;i*i<p.size();i++){
        if (p[i]) for (int j=i*i;j<p.size();j+=i) p[j] = false;
    }
    for (int i=2;i<p.size();i++) if (p[i]) prime.push_back(i);

}

bool isPrime(int n){
    for (int i=0;i<prime.size() && prime[i]*prime[i]<=n;i++) if (n%prime[i]==0) return false;
    return true;
}

void build(){
    for (int i=0;i<=10000;i++){
        int fc = i*i+i+41;
        func[i] = isPrime(fc);
    }
}

int main(){
    build_prime();
    build();
    int a,b;
    while (cin >>a >>b){
        double count = 0;
        for (int i=a;i<=b;i++) count += func[i];
        double ans = count/(b-a+1)*100+1e-8;
        printf("%.2lf\n",ans);
    }
}