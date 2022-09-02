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
    int n, k, r, c;
    cin >>n >>k >>r >>c;
    r %= k, c %= k;
    if (r==0) r = k;
    if (c==0) c = k;
    vector<vector<char>> bs(k, vector<char>(k,'.'));
    bs[r-1][c-1] = 'X', bs[c-1][r-1] = 'X';
    for (int i=0;i<k;i++){
        if (i==r-1 || i==c-1) continue;
        bs[i][i] = 'X';
    }
    for (int i=0;i<n/k;i++){
        for (int x=0;x<k;x++){
            for (int j=0;j<n/k;j++){
                for (int y=0;y<k;y++) cout <<bs[x][y];
            }
            cout <<endl;
        }
    }
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}