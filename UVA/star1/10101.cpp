#include <bits/stdc++.h>

#define ll long long

using namespace std;

int sz[4]{1,2,2,2};
string txt[4]{"shata","hajar","lakh","kuti"};

void solution1(){
    int cs = 1;
    string s;
    while (cin >>s){
        printf("%4d.",cs++);
        if (s.size()<=2){
            cout <<' ' <<s <<endl;
            continue;
        }
        vector<int> v;
        v.push_back(stoi(s.substr(s.size()-2,2)));
        for (int i=s.size()-2,j=0;i>0;){
            int tmp = i;
            i -= sz[j];
            if (i<0) i = 0;
            j = (j+1)%4;
            v.push_back(stoi(s.substr(i,tmp-i)));
        }
        int pos = (v.size()-2)%4;
        for (int i=v.size()-1;i>0;i--){
            if (v[i]==0 && pos==3) cout <<" kuti";
            else if (v[i]!=0){
                cout <<" " <<v[i];
                cout <<" " <<txt[pos];
            }
            pos = (pos-1+4)%4;
        }
        if (v[0]!=0) cout <<" " <<v[0] <<endl;
        else cout <<endl;
    }
}

void split(ll n){
    if (n>=10000000){
        split(n/10000000);
        cout <<" kuti";
        n %= 10000000;
    }
    if (n>=100000){
        split(n/100000);
        cout <<" lakh";
        n %= 100000;
    }
    if (n>=1000){
        split(n/1000);
        cout <<" hajar";
        n %= 1000;
    }
    if (n>=100){
        split(n/100);
        cout <<" shata";
        n %= 100;
    }
    if (n) cout <<" " <<n;
}

void solution2(){
    ll n;
    int cs = 1;
    while (cin >>n){
        printf("%4d.",cs++);
        if (n) split(n);
        else cout <<" 0";
        cout <<endl;
    }
}

int main(){
    solution2();
}