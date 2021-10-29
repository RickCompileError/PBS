#include <bits/stdc++.h>

using namespace std;

string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int percost[36];

int cal(int num, int base){
    int sum = 0;
    if (num==0) return percost[0];
    while (num>0) sum += percost[num%base], num /= base;
    return sum;
}

int main(){
    int cs; cin >>cs;
    for (int i=1;i<=cs;i++){
        printf("Case %d:\n",i);
        for (int i=0;i<36;i++) cin >>percost[i];
        int n, num; cin >>n;
        while (n--){
            cin >>num;
            printf("Cheapest base(s) for number %d:",num);
            int mn = -1;
            vector<int> ans;
            for (int i=2;i<=36;i++){
                int cost = cal(num,i);
                if (mn==-1 || cost<mn){
                    mn = cost;
                    ans.clear();
                    ans.push_back(i);
                }else if (cost==mn){
                    ans.push_back(i);
                }
            }
            for (int i: ans) cout <<" " <<i;
            cout <<endl;
        }
        if (i!=cs) cout <<endl;
    }
}