#include <stdio.h>

const int mxN = 5e2;

int main(){
    int J, R;
    while (scanf("%d%d",&J,&R)!=EOF && J!=0 && R!=0){
        int s, score[mxN];
        int i, j;
        for (i=0;i<mxN;i++) score[i] = 0;
        for (i=0;i<R;i++){
            for (j=0;j<J;j++){
                scanf("%d",&s);
                score[j] += s;
            }
        }
        int mx = 0;
        for (i=1;i<J;i++) if (score[i]>=score[mx]) mx = i;
        printf("%d\n",mx+1);
    }
    return 0;
}