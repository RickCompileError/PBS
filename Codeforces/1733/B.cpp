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
    int n, x, y;
    cin >>n >>x >>y;
    if (x<y) swap(x,y);
    if (x+y==0 || (x!=0 && y!=0) || ((n-1)%x)!=0){
        cout <<-1 <<endl;
        return;
    }
    for (int i=2;i<=n;i+=x){
        for (int k=0;k<x;k++) cout <<i <<' ';
    }
    cout <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}
