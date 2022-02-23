// This question has a problem.
// If I use normal array, it will be WA, but using vector, it will be AC
// And use C code also can AC

#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs; cin >>cs;
    for (int z=1;z<=cs;z++){
        printf("Case #%d: ",z);
        int n, k, m; cin >>n >>k >>m;
        vector<double> pro(n);
        for (int i = 0; i < n; i++) {
            cin >> pro[i];
        }
        vector<double> day(m+1,0.0);
        day[0] = 0.0, day[1] = pro[0];
        for (int i=2;i<=m;i++){
            for (int j=0;j<n;j++) day[i] += pro[j]*pow(day[i-1],j);
        }
        cout <<fixed <<setprecision(7) <<pow(day[m],k) <<endl;
    }
}