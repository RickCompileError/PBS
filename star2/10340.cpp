#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    while (cin >>a >>b){
        int A = a.size(), B = b.size(), i, j;
        for (i=0,j=0;i<A && j<B;){
            if (a[i]==b[j]) i++;
            j++;
        }
        cout <<(i==A?"Yes":"No") <<endl;
    }
}