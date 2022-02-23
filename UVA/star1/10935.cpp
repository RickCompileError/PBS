#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >>n && n!=0){
        queue<int> q;
        vector<int> d;
        for (int i=1;i<=n;i++) q.push(i);
        while (q.size()>1){
            d.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout <<"Discarded cards:";
        if (d.size()>=1){
            cout <<" " <<d[0];
            for (int i=1;i<d.size();i++) cout <<", " <<d[i];
        }
        cout <<"\nRemaining card: " <<q.front() <<endl;
    }
}