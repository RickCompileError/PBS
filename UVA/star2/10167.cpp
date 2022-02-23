#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x;
    int y;
} point[100];

int main(){
    int n;
    while (cin >>n && n!=0){
        for (int i=0;i<2*n;i++) cin >>point[i].x >>point[i].y;
        bool found = false;
        for (int i=-500;i<=500 && !found;i++){
            for (int j=-500;j<=500 && !found;j++){
                int pos=0, neg=0;
                for (int k=0;k<2*n;k++){
                    int f = point[k].x*i + point[k].y*j;
                    pos += f>0, neg += f<0;
                }
                if (pos==n && neg==n){
                    cout <<i <<' ' <<j <<endl;
                    found = true;
                }
            }
        }
    }
}