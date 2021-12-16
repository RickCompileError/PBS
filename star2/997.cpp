#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    int term;
    while ((c=getchar())!=EOF){
        vector<int> v;
        vector<char> op;
        while ((c=cin.peek())!=' '){
            if (c=='[' || c==']') getchar();
            else if (c=='+' || c=='*') op.push_back(getchar());
            else cin >>term, v.push_back(term);
        }
        cin >>term; getchar();
        vector<int> ans[v.size()];
        for (int i=0;i<term;i++){
            for (int j=v.size()-1;j>=0;j--){
                if (j==v.size()-1) ans[j].push_back(v[j]);
                else{
                    if (i==0){
                        if (op[j]=='+') ans[j].push_back(v[j]);
                        else ans[j].push_back(v[j]*ans[j+1][i]);
                    }else{
                        if (op[j]=='+') ans[j].push_back(ans[j][i-1]+ans[j+1][i-1]);
                        else ans[j].push_back(ans[j][i-1]*ans[j+1][i]);
                    }
                }
            }
            cout <<(i==0?"":" ") <<ans[0][i];
        }
        cout <<endl;
    }
}