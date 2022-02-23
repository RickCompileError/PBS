#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, a;
    while (cin >>x){
        getchar();
        vector<int> coe;
        do{
            cin >>a;
            coe.push_back(a);
        } while (getchar()!='\n');
        int ans = 0;
        for (int i=0,j=coe.size()-1;i<coe.size()-1;i++,j--){
            ans += coe[i]*j;
            if (i!=coe.size()-2) ans *= x;
        }
        cout <<ans <<endl;
    }
}