#include <bits/stdc++.h>

using namespace std;

const int mxL = 300;

int a[mxL], b[mxL], c[2*mxL];

int main(){
    string str;
    while (cin >>str){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for (int i=str.size()-1,j=0;i>=0;i--,j++) a[j] = str[i]-'0';
        cin >>str;
        for (int i=str.size()-1,j=0;i>=0;i--,j++) b[j] = str[i]-'0';
        for (int i=0;i<mxL;i++)
            for (int j=0;j<mxL;j++)
                c[i+j] += a[i]*b[j];
        for (int i=0;i<mxL*2-1;i++) c[i+1] += c[i]/10, c[i] %= 10;
        int len = mxL*2-1;
        while (len>=0 && !c[len]) len--;
        if (len<0) cout <<0 <<endl;
        else{
            for (;len>=0;len--) cout <<c[len];
            cout <<endl;
        }
    }
}