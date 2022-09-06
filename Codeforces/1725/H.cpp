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
    int a[n];
    vector<int> m[2];
    for (int i=0;i<n;i++){
        cin >>a[i];
        m[a[i]%3!=0].pb(i);
    }
    int z, c, cnt = n/2;
    string str(n,'0');
    if (m[0].size()>=m[1].size()){
        z = 2;
        c = 1;
    }else{
        z = 0;
        c = 0;
    }
    for (int i: m[c]) str[i]='1', cnt--;
    for (int i: m[1^c]){
        if (cnt==0) break;
        str[i]='1', cnt--;
    }
    cout <<z <<endl <<str <<endl;
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}

// cat(a,b)*cat(b,a) + a*b = sum(dig(ab))%3 * sum(dig(ba))%3 + sum(dig(a))%3 * sum(dig(b))%3
// sum(dig(ab)) = sum(dig(ba))

// 0*0+0*0 = 0(0,0)
// 1*1+0*1 = 1(0,1)
// 2*2+0*2 = 1(0,2)
// 2*2+1*1 = 2(1,1)
// 0*0+1*2 = 2(1,2)
// 1*1+2*2 = 2(2,2)

// (0,1,2) (0) o
// (0,1,2) (1) x
// (0,1,2) (2) x
// (0,1) (0,2) o
// (0,1) (0,1) x
// (0,2) (0,2) x
// (1,2) (0,1) x
// (1,2) (0,2) x
// (1,2) (1,2) o