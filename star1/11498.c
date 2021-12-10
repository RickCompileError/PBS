#include <stdio.h>
#include <stdbool.h>

int main(){
    int k;
    while (scanf("%d",&k)!=EOF && k!=0){
        int n, m, x, y;
        scanf("%d%d",&n,&m);
        while (k--){
            scanf("%d%d",&x,&y);
            int difx = x-n, dify = y-m;
            char *c;
            if (difx==0 || dify==0) c = "divisa";
            else if (difx<0 && dify<0) c = "SO";
            else if (difx<0 && dify>0) c = "NO";
            else if (difx>0 && dify<0) c = "SE";
            else c = "NE";
            printf("%s\n",c);
        }
    }
}