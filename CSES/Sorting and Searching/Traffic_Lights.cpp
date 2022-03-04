#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, n, p;
    cin >>x >>n;
    multiset<int> ms{x};
    set<int> si{0,x};
    while (n--){
        cin >>p;
        set<int>::iterator back = si.lower_bound(p), front = back;
        front--;
        si.insert(p);
        ms.erase(ms.find(*back-*front));
        ms.insert(*back-p), ms.insert(p-*front);
        cout <<*(ms.rbegin()) <<' ';
    }
}