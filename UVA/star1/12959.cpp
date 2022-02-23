#include <bits/stdc++.h>

using namespace std;

int main(){
    int J, R, s;
    while (cin >>J >>R){
        int score[J]{};
        for (int i=0;i<R;i++) for (int j=0;j<J;j++) cin >>s, score[j] += s;
        int mx = 0;
        for (int i=1;i<J;i++) if (score[i]>=score[mx]) mx = i;
        cout <<mx+1 <<endl;
    }
}