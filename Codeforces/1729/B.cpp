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
    int len;
    bool greater = false;
    cin >>len;
    string str, ans="";
    cin >>str;
    for (int i=len-1;i>=0;i--){
        if (greater) ans = (char)(96+stoi(str.substr(i-1,2))) + ans, i--, greater = false;
        else if (str[i]=='0') greater = true;
        else ans = (char)(96+str[i]-'0') + ans;
    }
    cout <<ans <<endl;
}

int main(){
    int t;
    cin >>t;
    // t = 1;
    while (t--) solve();
}
