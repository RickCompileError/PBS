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
    int n; cin >>n;
    if (n%2){
        cout <<1;
        for (int i=2;i<=n;i++) cout <<' ' <<(i%2?i-1:i+1);
    }else{
        for (int i=1;i<=n;i++) cout <<(i%2?i+1:i-1) <<' ';
    }
    cout <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}