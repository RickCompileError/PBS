// dimensions of upper block were both strictly smaller than dimensions of lower block
// It's a DP problem not a Greedy
#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef struct Block{
    int x, y, z;
    Block(int _x, int _y, int _z){
        x = _x;
        y = _y;
        z = _z;
    }
} block;

bool cmp(block &a, block &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y) || (a.x==b.x && a.y==b.y && a.z<b.z);
}

void sol2(){
    int n, cs=1;
    int x, y, z;
    while (cin >>n && n!=0){
        vector<block> v;
        while (n--){
            cin >>x >>y >>z;
            v.pb(block(x,y,z));
            v.pb(block(x,z,y));
            v.pb(block(y,x,z));
            v.pb(block(y,z,x));
            v.pb(block(z,x,y));
            v.pb(block(z,y,x));
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> dp;
        for (int i=0;i<v.size();i++){
            dp.pb(v[i].z);
            for (int j=0;j<i;j++){
                if (v[i].x>v[j].x && v[i].y>v[j].y) dp[i] = max(dp[i], dp[j]+v[i].z);
            }
        }
        int ans = 0;
        for (int i: dp) ans = max(ans, i);
        printf("Case %d: maximum height = %d\n", cs++, ans);
    }
}

int main(){
    sol2();
}