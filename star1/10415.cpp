#include <bits/stdc++.h>

using namespace std;

map<char,array<bool,10>> finger;

void build(){
    finger['c'] = {0,1,1,1,0,0,1,1,1,1};
    finger['d'] = {0,1,1,1,0,0,1,1,1,0};
    finger['e'] = {0,1,1,1,0,0,1,1,0,0};
    finger['f'] = {0,1,1,1,0,0,1,0,0,0};
    finger['g'] = {0,1,1,1,0,0,0,0,0,0};
    finger['a'] = {0,1,1,0,0,0,0,0,0,0};
    finger['b'] = {0,1,0,0,0,0,0,0,0,0};
    finger['C'] = {0,0,1,0,0,0,0,0,0,0};
    finger['D'] = {1,1,1,1,0,0,1,1,1,0};
    finger['E'] = {1,1,1,1,0,0,1,1,0,0};
    finger['F'] = {1,1,1,1,0,0,1,0,0,0};
    finger['G'] = {1,1,1,1,0,0,0,0,0,0};
    finger['A'] = {1,1,1,0,0,0,0,0,0,0};
    finger['B'] = {1,1,0,0,0,0,0,0,0,0};
}

int main(){
    build();
    int n; cin >>n; getchar();
    while (n--){
        string in; getline(cin,in,'\n');
        bool press[10]{0};
        int count[10]{0};
        for (char i: in){
            for (int j=0;j<10;j++){
                if (finger[i][j] && !press[j]) count[j]++, press[j] = true;
                else if (!finger[i][j]) press[j] = false;
            }
        }
        for (int i=0;i<10;i++){
            if (i!=0) cout <<' ';
            cout <<count[i];
        }
        cout <<endl;
    }
}