#include <bits/stdc++.h>

using namespace std;

// can show hand if not folded and all other players have status allin or folded
// means player him/herself status is allin or in
int main(){
    int len; cin >>len; getchar();
    map<char, int> m;
    for (int i=0;i<len;i++) m[getchar()]++;
    if (m['I']>1) cout <<0 <<endl;
    else if (m['I']==1) cout <<1 <<endl;
    else cout <<m['A'] <<endl;
}