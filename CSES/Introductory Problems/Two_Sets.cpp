#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    if ((n+1)/2%2) cout <<"NO\n";
    else{
        cout <<"YES\n";
        int half = (n+1)/2, hhalf = half/2;
        cout <<half <<endl;
        for (int i=1;i<=half-hhalf;i++) cout <<i <<' ';
        if (n%2) cout <<half <<' ';
        for (int i=half+hhalf+1;i<=n;i++) cout <<i <<' ';
        cout <<endl <<n/2 <<endl;
        for (int i=half-hhalf+1;i<=half+hhalf;i++){
            if (n%2 && i==half) continue;
            cout <<i <<' ';
        }
        cout <<endl;
    }
}
/* 
Example:
    11:
        6
        1 2 3 6 10 11
        4
        4 5 7 8 9
    12:
        6
        1 2 3 10 11 12
        6
        4 5 6 7 8 9
 */