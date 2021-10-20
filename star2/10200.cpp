#include <bits/stdc++.h>

using namespace std;

bool func[10001]{false};

bool isPrime(int n){
    for (int i=2;i*i<=n;i++) if (n%i==0) return false;
    return true;
}

void build(){
    for (int i=0;i<=10000;i++){
        int fc = i*i+i+41;
        func[i] = isPrime(fc);
    }
}

int main(){
    build();
    int a,b;
    while (cin >>a >>b){
        float count = 0;
        for (int i=a;i<=b;i++) count += func[i];
        float ans = round(count/(b-a+1)*10000)/100;
        printf("%.2f\n",ans);
    }
}