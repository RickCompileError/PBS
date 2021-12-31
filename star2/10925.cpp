#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bill;

void print(){
    int i=bill[0].size()-1;
    while (bill[0][i]==0) i--;
    if (i<0) cout <<0;
    else for (;i>=0;i--) cout <<bill[0][i];
}

void divide(int div){
    int remainder = 0;
    for (int i=bill[0].size()-1;i>=0;i--){
        bill[0][i] += remainder*10;
        remainder = bill[0][i]%div;
        bill[0][i] /= div;
    }
}

void sum(){
    for (int i=bill.size()-1;i-1>=0;i--){
        int carry = 0;
        for (int j=0;j<max(bill[i-1].size(),bill[i].size()) || carry;j++){
            if (j==bill[i-1].size()) bill[i-1].push_back(0);
            bill[i-1][j] += (j<bill[i].size()?bill[i][j]:0)+carry;
            carry = (bill[i-1][j]>=10);
            bill[i-1][j] %= 10;
        }
    }
}

int main(){
    int n, f, cs = 1;
    string str;
    while (cin >>n >>f && n!=0 && f!=0){
        cout <<"Bill #" <<cs++ <<" costs ";
        bill.clear();
        for (int i=0;i<n;i++){
            bill.push_back(vector<int>());
            cin >>str;
            for (int j=str.size()-1;j>=0;j--) bill[i].push_back(str[j]-'0');
        }
        sum();
        print();
        divide(f);
        cout <<": each friend should pay ";
        print();
        cout <<endl <<endl;
    }
}