#include <bits/stdc++.h>

#define ll long long

using namespace std;

// this function can show x^x last digit
// we can get below cycle
// 20 number a group
// 1 4 7 6 5 6 3 6 9 0
// 1 6 3 6 5 6 7 4 9 0
// sum of those digits by group
// 4 8 2 6 0
void find_cycle(){
    for (int k=0;k<10;k++){
        for (int i=k*10+1;i<=(k+1)*10;i++){
            int tmp = i;
            for (int j=1;j<i;j++) tmp*=i, tmp%=10;
            cout <<tmp <<' ';
        }
        cout <<endl;
    }
}

int cycle[20]{0,1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9};
int sum_cycle[5]{0,4,8,2,6};

int main(){
    string str;
    while (cin >>str && str!="0"){
        int num = str[str.size()-1]-'0', ans = 0;
        if (str.size()>1) num += (str[str.size()-2]-'0')*10;
        ans += sum_cycle[num/20], num %= 20;
        for (int i=0;i<=num;i++) ans += cycle[i];
        cout <<ans%10 <<endl;
    }
}