#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define st first
#define nd second

using namespace std;

const int mx = 1005;
int n, r, c, ans;
char m[mx][mx]{};
int F[mx][mx]{}, J[mx][mx]{};
bool visited[mx][mx]{};

void fdfs(queue<pair<int,int>> fq){
    int x, y;
    while (!fq.empty()){
        x = fq.front().st, y = fq.front().nd, fq.pop();
        if (x-1>0 && F[x-1][y]==INF) F[x-1][y] = F[x][y] + 1, fq.push({x-1, y});
        if (x+1<=r && F[x+1][y]==INF) F[x+1][y] = F[x][y] + 1, fq.push({x+1, y});
        if (y-1>0 && F[x][y-1]==INF) F[x][y-1] = F[x][y] + 1, fq.push({x, y-1});
        if (y+1<=c && F[x][y+1]==INF) F[x][y+1] = F[x][y] + 1, fq.push({x, y+1});
    }
}

void jdfs(queue<pair<int,int>> j){
    int x, y;
    while (!j.empty()){
        x = j.front().st, y = j.front().nd, j.pop();
        if (x-1<=0) ans = min(ans, J[x][y]+1);
        else if (!visited[x-1][y]){
            J[x-1][y] = (J[x][y]+1<F[x-1][y]?J[x][y]+1:-1);
            visited[x-1][y] = true;
            if (J[x-1][y]!=-1) j.push({x-1,y});
        }
        if (x+1>r) ans = min(ans, J[x][y]+1);
        else if (!visited[x+1][y]){
            J[x+1][y] = (J[x][y]+1<F[x+1][y]?J[x][y]+1:-1);
            visited[x+1][y] = true;
            if (J[x+1][y]!=-1) j.push({x+1,y});
        }
        if (y-1<=0) ans = min(ans, J[x][y]+1);
        else if (!visited[x][y-1]){
            J[x][y-1] = (J[x][y]+1<F[x][y-1]?J[x][y]+1:-1);
            visited[x][y-1] = true;
            if (J[x][y-1]!=-1) j.push({x,y-1});
        }
        if (y+1>c) ans = min(ans, J[x][y]+1);
        else if (!visited[x][y+1]){
            J[x][y+1] = (J[x][y]+1<F[x][y+1]?J[x][y]+1:-1);
            visited[x][y+1] = true;
            if (J[x][y+1]!=-1) j.push({x,y+1});
        }
    }
}

void sol1(){
    cin >>n;
    while (n--){
        cin >>r >>c;
        ans = INF;
        memset(m, 0, sizeof(m));
        memset(J, INF, sizeof(J));
        memset(F, INF, sizeof(F));
        memset(visited, 0, sizeof(visited));
        queue<pair<int,int>> jq, fq;
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                cin >>m[i][j];
                if (m[i][j]=='#') F[i][j] = J[i][j] = -1;
                if (m[i][j]=='F') F[i][j] = 0, fq.push({i,j});
                if (m[i][j]=='J') J[i][j] = 0, jq.push({i,j});
            }
        }
        fdfs(fq);
        jdfs(jq);
        if (ans==INF) cout <<"IMPOSSIBLE\n";
        else cout <<ans <<endl;
    }
}


int direction[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
struct Place{
    int x, y;
};
Place pj, pf;
queue<Place> qp;

void dfs(){
    while (!qp.empty()) qp.pop();
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            if (m[i][j]=='F'){
                pf.x = i, pf.y = j;
                qp.push(pf);
                F[i][j] = 1;
            }
        }
    }
    Place nxt, cur;
    while (!qp.empty()){
        cur = qp.front();
        qp.pop();
        for (int i=0;i<4;i++){
            nxt.x = cur.x+direction[i][0];
            nxt.y = cur.y+direction[i][1];
            if (nxt.x<=0 || nxt.x>r || nxt.y<=0 || nxt.y>c) continue;
            if (m[nxt.x][nxt.y]=='#') continue;
            if (F[nxt.x][nxt.y]==0){
                F[nxt.x][nxt.y] = F[cur.x][cur.y] + 1;
                qp.push(nxt);
            }
        }
    }
    qp.push(pj), J[pj.x][pj.y] = 1;
    while (!qp.empty()){
        cur = qp.front();
        qp.pop();
        if (cur.x==1 || cur.x==r || cur.y==1 || cur.y==c){
            cout <<J[cur.x][cur.y] <<endl;
            return;
        }
        for (int i=0;i<4;i++){
            nxt.x = cur.x+direction[i][0];
            nxt.y = cur.y+direction[i][1];
            if (nxt.x<=0 || nxt.x>r || nxt.y<=0 || nxt.y>c) continue;
            if (m[nxt.x][nxt.y]=='#') continue;
            if (J[nxt.x][nxt.y]==0 && (F[nxt.x][nxt.y]>J[cur.x][cur.y]+1 || F[nxt.x][nxt.y]==0)){
                J[nxt.x][nxt.y] = J[cur.x][cur.y] + 1;
                qp.push(nxt);
            }
        }
    }
    cout <<"IMPOSSIBLE" <<endl;
}

// more simplify
void sol2(){
    cin >>n;
    while (n--){
        cin >>r >>c;
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                cin >>m[i][j];
                if (m[i][j]=='J') pj.x = i, pj.y = j;
                F[i][j] = J[i][j] = 0;
            }
        }
        dfs();
    }
}

int main(){
    sol2();
}