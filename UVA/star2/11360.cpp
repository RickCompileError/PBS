#include <bits/stdc++.h>

using namespace std;

const int mxN = 10;
int T, N, M, a, b;
char c;
string str;
int matrix[mxN][mxN];

void row(){
    for (int i=0;i<N;i++){
        swap(matrix[a][i],matrix[b][i]);
    }
}

void col(){
    for (int i=0;i<N;i++){
        swap(matrix[i][a],matrix[i][b]);
    }
}

void inc(){
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) matrix[i][j] = (matrix[i][j]+1)%10;
}

void dec(){
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) matrix[i][j] = (matrix[i][j]+9)%10;
}

void transpose(){
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main(){
    cin >>T;
    for (int cs=1;cs<=T;cs++){
        memset(matrix,0,sizeof(matrix));
        cin >>N;
        for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >>c, matrix[i][j] = c-'0';
        cin >>M;
        while (M--){
            cin >>str;
            if (str=="row") cin >>a >>b, a--, b--, row();
            else if (str=="col") cin >>a >>b, a--, b--, col();
            else if (str=="inc") inc();
            else if (str=="dec") dec();
            else transpose();
        }
        cout <<"Case #" <<cs <<endl;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++) cout <<matrix[i][j];
            cout <<endl;
        }
        cout <<endl;
    }
}