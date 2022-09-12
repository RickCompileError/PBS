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
    int i=2;
    ll tmp1, tmp2;
    while (true){
        for (int i=1;;i++){
            for (int j=1;j<i;j++){
                cout <<"? " <<i <<' ' <<j <<endl;
                cin >>tmp1;
                cout <<"? " <<j <<' ' <<i <<endl;
                cin >>tmp2;
                if (tmp1==-1 || tmp2==-1){
                    cout <<"! " <<i-1 <<endl;
                    return;
                }
                if (tmp1!=tmp2){
                    cout <<"! " <<tmp1+tmp2 <<endl;
                    return;
                }
            }
        }
    }
}

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve();
}
