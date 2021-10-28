#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    bool quote = true;
    while (getline(cin,s,'\n')){
        for (char i: s){
            if (i=='"'){
                cout <<(quote?"``":"''");
                quote = !quote;
            }else{
                cout <<i;
            }
        }
        cout <<endl;
    }
}