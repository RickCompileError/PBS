#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define pll pair<ll,ll>
#define e1 first
#define e2 second
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back

using namespace std;

void solve(){
    int t; cin >>t;
    int a[t];
    bool zero = false;
    for (int i=0;i<t;i++){
        cin >>a[i];
        while (a[i]%10!=0 && a[i]%10!=2) a[i] += a[i]%10;
        if (a[i]%10==0) zero = true;
    }
    if (zero){
        bool same = true;
        for (int i=1;i<t && same;i++) same = (a[i]==a[0]);
        cout <<(same?"YES":"NO") <<endl;
        return;
    }
    for (int i=0;i<t;i++) a[i] /= 10;
    int isEven = true;
    for (int i=1;i<t && isEven;i++) isEven = ((a[i]-a[0])%2==0);
    cout <<(isEven?"YES":"NO") <<endl; 
}

int main(){
    int t; cin >>t;
    while (t--) solve();
}

// 1: 1 2
// 2: 2 4
// 3: 3 6
// 4: 4 8
// 5: 5 0
// 6: 6 2
// 7: 7 4
// 8: 8 6
// 9: 9 8
// 0: 0 0
// (1,3,7,9) -> (2,4,8,6)
// (5) -> (0)