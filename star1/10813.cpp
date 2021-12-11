#include <bits/stdc++.h>

#define coor pair<int,int>

using namespace std;

map<int,coor> m;
bool exist[5][5];

bool bingo(int r, int c){
    bool row = true, col = true, dig1 = (r-c==0), dig2 = (r+c==4);
    if (dig1) for (int i=0;i<5;i++) if (!exist[i][i]) dig1 = false;
    if (dig2) for (int i=0;i<5;i++) if (!exist[i][4-i]) dig2 = false;
    for (int i=0;i<5;i++){
        if (!exist[r][i]) row = false;
        if (!exist[i][c]) col = false;
    }
    return row || col || dig1 || dig2;
}

int main(){
    int n, num; cin >>n;
    while (n--){
        m.clear();
        for (int i=0;i<5;i++) memset(exist[i],0,sizeof(exist[i]));
        exist[2][2] = true;
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
                if (i==2 && j==2) continue;
                cin >>num;
                m[num] = {i,j};
            }
        }
        int ans = 0;
        for (int i=1;i<=75;i++){
            cin >>num;
            if (m.find(num)==m.end()) continue;
            coor c = m[num];
            exist[c.first][c.second] = true;
            if (bingo(c.first,c.second) && !ans) ans = i;
        }
        cout <<"BINGO after " <<ans <<" numbers announced\n";
    }
}