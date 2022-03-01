#include <bits/stdc++.h>

using namespace std;

// check value v
int check_front_end(int pos[], int sz, int v){
    return (v>0 && pos[v-1]>pos[v]) + (v+1<sz && pos[v]>pos[v+1]);
}

// count the number of the decrease order at the position of value a & b,
// and minus 1 if a & b is adjacent and the position of value a > b
int check(int pos[], int sz, int a, int b){
    return check_front_end(pos,sz,a) + check_front_end(pos,sz,b) - (abs(a-b)==1 && pos[a]>pos[b]);
}

int main(){
    int n, m, a, b, va, vb, ans = 1;
    cin >>n >>m;
    int val[n], pos[n];
    for (int i=0;i<n;i++) cin >>val[i];
    for (int i=0;i<n;i++) pos[val[i]-1] = i;
    for (int i=1;i<n;i++) ans += (pos[i]<pos[i-1]);
    while (m--){
        cin >>a >>b;
        swap(val[a-1],val[b-1]); // swap the value of position (a,b)
        va = val[a-1]-1, vb = val[b-1]-1; // record the value of position (a,b)
        if (va>vb) swap(va,vb); // va must smaller than vb
        ans -= check(pos,n,va,vb);
        swap(pos[va],pos[vb]); // swap (va,vb) position
        ans += check(pos,n,va,vb);
        cout <<ans <<endl;
    }
}