#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char in[1005];
    while (scanf("%s",in)!=EOF){
        int i, result = 0, sz = strlen(in), sign = 1;
        if (in[0]=='0' && strlen(in)==1) break;
        for (i=0;i<sz;i++){
            result += (in[i]-'0')*sign;
            sign *= -1;
        }
        printf("%s is%s a multiple of 11.\n",in,(result%11==0?"":" not"));
    }
    return 0;
}