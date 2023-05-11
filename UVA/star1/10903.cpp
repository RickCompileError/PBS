#include <bits/stdc++.h>

using namespace std;

map<string,int> type{
    {"rock", 0}, 
    {"paper", 1},
    {"scissors", 2}
};

int main(){
    int n, k, gm, a, b;
    string at, bt;
    bool first_time{1};
    while (cin >>n && n!=0){
        cout <<(first_time?"":"\n");
        cin >>k;
        gm = k*n*(n-1)/2;
        float py_win[n+1]{0};
        float py_tot[n+1]{0};
        for (int i=0;i<gm;i++){
            cin >>a >>at >>b >>bt;
            if (type[at]==0 && type[bt]==1) py_win[b]++;
            if (type[at]==1 && type[bt]==0) py_win[a]++;
            if (type[at]==0 && type[bt]==2) py_win[a]++;
            if (type[at]==2 && type[bt]==0) py_win[b]++;
            if (type[at]==1 && type[bt]==2) py_win[b]++;
            if (type[at]==2 && type[bt]==1) py_win[a]++;
            if (type[at] != type[bt]) py_tot[a]++, py_tot[b]++;
        }
        for (int i=1;i<=n;i++){
            if (py_tot[i]==0) cout <<"-\n";
            else printf("%.3f\n", py_win[i]/py_tot[i]);
        }
        first_time = false;
    }
}