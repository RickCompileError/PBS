#include <bits/stdc++.h>

using namespace std;

void solution1(){
    int n, k, start = 1, ans = 0;
    map<int,int> m;
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>k;
        if (m[k]==0){
            m[k] = i;
        }else{
            if (m[k]>=start) start = m[k] + 1;
            m[k] = i;
        }
        ans = max(ans,i-start+1);
    }
    cout <<ans <<endl;
}

void solution2(){
    int n, k, ans = 0;
    set<int> s;
    queue<int> q;
    cin >>n;
    while (n--){
        cin >>k;
        if (s.find(k)==s.end()) s.insert(k), q.push(k);
        else{
            while (q.front()!=k) s.erase(q.front()), q.pop();
            q.pop(), q.push(k);
        }
        ans = max(ans,(int)q.size());
    }
    cout <<ans <<endl;
}

int main(){
    solution2();
}