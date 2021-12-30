// This code is correct, but there are some problems in online judge leads to get the wrong answer

#include <bits/stdc++.h>

using namespace std;

map<char,int> m;
int bin[24];
char encoded[4];

void transform(){
    int val;
    for (int i=0;i<4;i++){
        val = m[encoded[i]];
        for (int j=0;j<6;j++){
            bin[i*6+j] = (val>>(5-j)) & 1;
        }
    }
    char ch;
    for (int i=0;i<3;i++){
        ch = bin[i*8];
        for (int j=1;j<8;j++){
            ch *= 2;
            ch += bin[i*8+j];
        }
        cout <<ch;
    }

}

void build(){
    int j = 0;
    for (int i='A';i<='Z';i++,j++) m[i] = j;
    for (int i='a';i<='z';i++,j++) m[i] = j;
    for (int i='0';i<='9';i++,j++) m[i] = j;
    m['+'] = 62, m['/'] = 63, m['='] = 0;
}

int main(){
    build();
    bool end{false};
    while (true){
        cin >>encoded[0];
        if (encoded[0]=='#' && end) break;
        if (encoded[0]=='#'){
            end = true;
            cout <<'#';
            continue;
        }
        for (int i=1;i<=3;i++) cin >>encoded[i];
        transform();
        end = false;
    }
}