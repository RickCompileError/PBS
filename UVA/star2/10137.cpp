// Debug input can't AC

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >>n && n!=0){
        double m[n], sum = 0, ans1 = 0, ans2 = 0;
        for (int i=0;i<n;i++) cin >>m[i], sum += m[i];
        sum = floor(sum*100/n+0.5)/100;
        for (int i=0;i<n;i++){
            if (m[i]>sum) ans1 += m[i]-sum;
            else if (m[i]<sum) ans2 += sum-m[i];
        }
        printf("$%.2lf\n",(ans1<ans2?ans1:ans2));
    }
}