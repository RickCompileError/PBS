#include <bits/stdc++.h>

using namespace std;

int main(){
    int cs; cin >>cs;
    bool first = true;
    while (cs--){
        if (!first) cout <<endl;
        int n; cin >>n;
        int speed[n]; for (int i=0;i<n;i++) cin >>speed[i];
        sort(speed,speed+n);
        int i = n-1, ans = 0;
        vector<vector<int>> order;
        for (;i>2;i-=2){
            if (2*speed[0]+speed[i-1]+speed[i]<speed[0]+2*speed[1]+speed[i]){
                order.push_back(vector<int>{speed[0],speed[i]});
                order.push_back(vector<int>{speed[0]});
                order.push_back(vector<int>{speed[0],speed[i-1]});
                order.push_back(vector<int>{speed[0]});
                ans += 2*speed[0]+speed[i-1]+speed[i];
            }else{
                order.push_back(vector<int>{speed[0],speed[1]});
                order.push_back(vector<int>{speed[0]});
                order.push_back(vector<int>{speed[i-1],speed[i]});
                order.push_back(vector<int>{speed[1]});
                ans += speed[0]+2*speed[1]+speed[i];
            }
        }
        if (i==2){
            order.push_back(vector<int>{speed[0],speed[2]});
            order.push_back(vector<int>{speed[0]});
            order.push_back(vector<int>{speed[0],speed[1]});
            ans += speed[0]+speed[1]+speed[2];
        }else if (i==1){
            order.push_back(vector<int>{speed[0],speed[1]});
            ans += speed[1];
        }else if (i==0){
            order.push_back(vector<int>{speed[0]});
            ans += speed[0];
        }
        cout <<ans <<endl;
        for (vector<int> i: order){
            for (int j=0;j<i.size();j++){
                if (j>0) cout <<' ' <<i[j];
                else cout <<i[j];
            }
            cout <<endl;
        }
        first = false;
    }
}