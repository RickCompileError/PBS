#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> step;

void print(int s, int e){
    cout <<s <<' ' <<e <<endl;
}

void recur(int n, int start, int end){
    if (n==1){
        print(start,end);
        return;
    }
    int next = 6-start-end; // position only 1 2 3, so minus start and end can get next
    recur(n-1,start,next);
    print(start,end);
    recur(n-1,next,end);
}

int main(){
    int n, ans=0;
    cin >>n;
    for (int i=1;i<=n;i++) ans = 2*ans+1;
    cout <<ans <<endl;
    recur(n,1,3);
}