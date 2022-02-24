#include <bits/stdc++.h>

using namespace std;

int dirx[4]{0,0,-1,1};
int diry[4]{1,-1,0,0};
bool board[9][9]{{}};
string input;
int dir[48];
int ans = 0;

void bfs(int ind = 0, int x = 1, int y = 1){
    if (x==1 && y==7){
        if (ind==input.size()) ans++;
        return;
    }
    if (ind==input.size()) return;
    if ((board[x][y-1] && board[x][y+1]) && (!board[x-1][y] && !board[x+1][y])) return;
    if ((board[x-1][y] && board[x+1][y]) && (!board[x][y-1] && !board[x][y+1])) return;
    board[x][y] = true;
    int tmpx, tmpy;
    if (dir[ind] == 4){
        for (int i=0;i<4;i++){
            tmpx = x+dirx[i], tmpy = y+diry[i];
            if (!board[tmpx][tmpy]) bfs(ind+1, tmpx, tmpy);
        }
    }else{
        tmpx = x+dirx[dir[ind]], tmpy = y+diry[dir[ind]];
        if (!board[tmpx][tmpy]) bfs(ind+1, tmpx, tmpy);
    }
    board[x][y] = false;
}

int main(){
    cin >>input;
    for (int i=0;i<48;i++){
        if (input[i]=='D') dir[i] = 0;
        if (input[i]=='U') dir[i] = 1;
        if (input[i]=='L') dir[i] = 2;
        if (input[i]=='R') dir[i] = 3;
        if (input[i]=='?') dir[i] = 4;
    }
    for (int i=0;i<9;i++) board[0][i] = board[i][0] = board[8][i] = board[i][8] = true;
    bfs();
    cout <<ans <<endl;
}