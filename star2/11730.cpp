#include <bits/stdc++.h>

using namespace std;

const int sz = 1e3+1;
vector<int> prime;
int ans[sz][sz]{{0}};

void build_prime(){
    bool p[500]{false};
    for (int i=2;i*i<=500;i++){
        if (!p[i]) for (int j=2*i;j<=500;j+=i) p[j] = true;
    }
    for (int i=2;i<=500;i++) if (!p[i]) prime.push_back(i);
}

/*********************************solution1*********************************/

void bfs(int num){
    queue<int> q;
    q.push(num);
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        for (int i: prime){
            if (i>=tmp || tmp+i>=sz) break;
            if (tmp%i==0 && ans[num][tmp+i]==-1){
                ans[num][tmp+i] = ans[num][tmp]+1;
                q.push(tmp+i);
            }
        }
    }
}

void build_answer(){
    for (int i=1;i<sz;i++) for (int j=i;j<sz;j++) ans[i][j] = (i==j?0:-1);
    for (int i=1;i<sz;i++) bfs(i);
}

void solution1(){
    build_prime();
    build_answer();
    int a, b, cs = 1;
    while (cin >>a >>b && a && b) printf("Case %d: %d\n",cs++,(a<=b&&a>0&&b>0?ans[a][b]:-1));
}

/*********************************solution1*********************************/

int bfs(int a, int b){
    int step[sz]{};
    queue<int> q;
    q.push(a);
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        for (int i: prime){
            if (i>=tmp || tmp+i>b) break;
            if (tmp%i==0){
                if (tmp+i==b) return step[tmp]+1;
                else if (tmp+i<b && !step[tmp+i]){
                    step[tmp+i] = step[tmp]+1;
                    q.push(tmp+i);
                }
            }
        }
    }
    return -1;
}

void solution2(){
    build_prime();
    int a, b, cs = 1;
    while (cin >>a >>b && a && b) printf("Case %d: %d\n",cs++,(a==b?0:bfs(a,b)));
}

/*********************************solution2*********************************/

int main(){
    solution1();
}