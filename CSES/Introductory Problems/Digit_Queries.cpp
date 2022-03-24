#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll q, k;
    cin >>q;
    while (q--){
        cin >>k;
        ll size = 9, len = 1, count = 0;   
        while (count+size*len<k) count += size*len, size *= 10, len++;
        k -= count;
        ll ans = (ll)pow(10,(len-1)) + (k-1)/len;
        string s = to_string(ans);
        cout <<s[(k-1)%len] <<endl;
    }
}