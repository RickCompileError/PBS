#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs, q;
    cin >>cs;
    while (cs--){
        cin >>q;
        vector<int> ans;
        int i = 9;
        while (q>=10 && i>1){
            if (q%i) i--;
            else ans.push_back(i), q /= i;
        }
        if (q>10) cout <<-1 <<endl;
        else if (ans.size()>0){
            ans.push_back(q);
            for (int i=ans.size()-1;i>=0;i--) cout <<ans[i];
            cout <<endl;
        }
        else if (q<10) cout <<q <<endl;
    }
}