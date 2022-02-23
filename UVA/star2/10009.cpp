#include <bits/stdc++.h>

using namespace std;

int ans = 0;
vector<int> city[26];
deque<int> q;

bool bfs(int current, int end, int previous=-1){
    q.push_back(current);
    if (current==end) return true;
    for (int i: city[current]){
        if (i==previous) continue;
        if(bfs(i,end,current)) return true;
    }
    q.pop_back();
    return false;
}

int main(){
    int ts; cin >>ts;
    bool next = false;
    while (ts--){
        if (next) cout <<endl;
        for (int i=0;i<26;i++) city[i].clear();
        int m, n, n1, n2; cin >>m >>n;
        string c1, c2;
        while (m--){
            cin >>c1 >>c2;
            n1 = c1[0]-'A', n2 = c2[0]-'A';
            city[n1].push_back(n2), city[n2].push_back(n1);
        }
        while (n--){
            q.clear();
            cin >>c1 >>c2;
            n1 = c1[0]-'A', n2 = c2[0]-'A';
            bfs(n1,n2);
            for (int i: q) cout <<(char)(i+'A');
            cout <<endl;
        }
        next = true;
    }
}