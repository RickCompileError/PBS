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
    int n, m;
    cin >>n >>m;
    if (n>m){
        cout <<"NO\n";
        return;
    }
    if (n%2){
        cout <<"YES\n" <<m-n+1;
        for (int i=1;i<=n-1;i++) cout <<' ' <<1;
        cout <<endl;
    }else{
        if (m%2){
            cout <<"NO\n";
            return;
        }
        cout <<"YES\n";
        for (int i=1;i<=n-2;i++) cout <<m/n <<' ';
        cout <<m/n+m%n/2 <<' ' <<m/n+m%n/2 <<endl;
        
    }
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}