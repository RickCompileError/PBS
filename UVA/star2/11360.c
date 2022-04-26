#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mxN 10

int T, N, M, i, j, cs;
int mtx[mxN][mxN];
char ch, *str;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void row(int a, int b){
    for (i=0;i<N;i++) swap(&mtx[a][i],&mtx[b][i]);
}

void col(int a, int b){
    for (i=0;i<N;i++) swap(&mtx[i][a],&mtx[i][b]);
}

void inc(){
    for (i=0;i<N;i++) for (j=0;j<N;j++) mtx[i][j] = (mtx[i][j]+1)%10;
}

void dec(){
    for (i=0;i<N;i++) for (j=0;j<N;j++) mtx[i][j] = (mtx[i][j]+9)%10;
}

void transpose(){
    for (i=0;i<N;i++) for (j=i+1;j<N;j++) swap(&mtx[i][j],&mtx[j][i]);
}

int main(){
    int a, b;
    scanf("%d",&T);
    for (cs=1;cs<=T;cs++){
        memset(mtx,0,sizeof(mtx));
        scanf("%d",&N);
        for (i=0;i<N;i++){
            getchar();
            for (j=0;j<N;j++) scanf("%c",&ch), mtx[i][j] = ch-'0';
        }
        scanf("%d",&M);
        while (M--){
            str = (char*)malloc(sizeof(char*));
            getchar();
            scanf("%s",str);
            if (strcmp(str,"row")==0) scanf("%d%d",&a,&b), row(--a,--b);
            else if (strcmp(str,"col")==0) scanf("%d%d",&a,&b), col(--a,--b);
            else if (strcmp(str,"inc")==0) inc();
            else if (strcmp(str,"dec")==0) dec();
            else transpose();
        }
        printf("Case #%d\n",cs);
        for (i=0;i<N;i++){
            for (j=0;j<N;j++) printf("%d",mtx[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}