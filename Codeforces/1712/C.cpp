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
#define rep(i, l, r) for (int i=l;i<=r;i++)
#define repn(i, l, r) for (int i=l;i<r;i++)

using namespace std;

void solve(){
    int n; cin >>n;
    int a[n]; for (int i=0;i<n;i++) cin >>a[i];
    set<int> s;
    int ans = 0;
    bool pass;
    do{
        pass = true;
        for (int i=n-1;i>=0;i--){
            if (s.find(a[i])!=s.end()) a[i] = 0;
            if (i<n-1 && a[i]>a[i+1]){
                s.insert(a[i]);
                a[i] = 0;
                ans++;
                pass = false;
            }
        }
    } while (!pass);
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}