#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int mxN = 15;

int main(){
    int t;
    scanf("%d",&t);
    int tuple[mxN];
    while (t--){
        int n;
        int tuple[mxN];
        bool allzero;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&tuple[i]);
        for (int i=0;i<1000;i++){
            int tmp = tuple[0];
            allzero = true;
            for (int j=0;j<n;j++){
                if (j!=n-1) tuple[j] = abs(tuple[j]-tuple[j+1]);
                else tuple[j] = abs(tuple[j]-tmp);
                if (tuple[j]) allzero = false;
            }
            if (allzero) break;
        }
        printf("%s\n",(allzero?"ZERO":"LOOP"));
    }
}