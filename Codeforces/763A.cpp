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

const int mxN = 1e5+5;
vector<int> tree[mxN];
int color[mxN]{0};

/******************** time out ***********************/
bool dfs(int cur, int prev, int c){
    bool check = (color[cur]==c);
    for (int i: tree[cur]){
        if (i==prev) continue;
        check &= dfs(i, cur, c);
    }
    return check;
}

// time out
void solve(){
    int n, u, v;
    set<int> c;
    cin >>n;
    for (int i=1;i<n;i++) cin >>u >>v, tree[u].pb(v), tree[v].pb(u);
    for (int i=1;i<=n;i++) cin >>color[i], c.insert(color[i]);
    for (int i=1;i<=n;i++){
        bool check = true;
        for (int j: tree[i]){
            check &= dfs(j, i, color[j]);
            if (!check) break;
        }
        if (check){
            cout <<"YES" <<endl <<i <<endl;
            return;
        }
    }
    cout <<"NO" <<endl;
}
/*********************************************************/


/************************ Accepted ***********************/
int curr_color;
bool ok;

void dfs2(int cur, int prev){
	ok &= color[cur]==curr_color;
	for (int i: tree[cur]){
		if (i==prev) continue;
		dfs2(i, cur);
	}
}

bool check(int p){
	bool same = true;
	for (int i: tree[p]){
		curr_color = color[i];
		ok = true;
		dfs2(i, p);
		same &= ok;
	}
	return same;
}

void solve2(){
    int n, u, v;
    cin >>n;
    for (int i=1;i<n;i++) cin >>u >>v, tree[u].pb(v), tree[v].pb(u);
    for (int i=1;i<=n;i++) cin >>color[i];
    int p1{0}, p2{0};
    for (int i=1;i<=n;i++){
        for (int j: tree[i]){
            if (color[i]!=color[j]) p1 = i, p2 = j;
        }
    }
    if (!p1) cout <<"YES" <<endl <<1 <<endl;
	else if (check(p1)) cout <<"YES" <<endl <<p1 <<endl;
	else if (check(p2)) cout <<"YES" <<endl <<p2 <<endl;
	else cout <<"NO" <<endl;
}
/***************************************************************/

int main(){
    int t;
    // cin >>t;
    t = 1;
    while (t--) solve2();
}