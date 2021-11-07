#include <bits/stdc++.h>

using namespace std;

int die[6]{1,2,6,5,3,4};

void init(){
    die[0] = 1, die[1] = 2, die[2] = 6;
    die[3] = 5, die[4] = 3, die[5] = 4;
}

void rotate(int a, int b, int c, int d){
    int tmp = die[a];
    die[a] = die[d];
    die[d] = die[c];
    die[c] = die[b];
    die[b] = tmp;
}

int main(){
    int n;
    while (cin >>n && n!=0){
        string s;
        init();
        while (n--){
            cin >>s;
            if (s=="north") rotate(0,1,2,3);
            else if (s=="south") rotate(0,3,2,1);
            else if (s=="east") rotate(0,5,2,4);
            else rotate(0,4,2,5);
        }
        cout <<die[0] <<endl;
    }
}