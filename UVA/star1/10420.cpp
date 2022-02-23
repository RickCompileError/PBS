#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >>n;
    string country;
    map<string,int> woman;
    for (int i=0;i<n;i++){
        cin >>country;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        woman[country]++;
    }
    for (map<string,int>::iterator i=woman.begin();i!=woman.end();i++) 
        cout <<i->first <<' ' <<i->second <<endl;
}