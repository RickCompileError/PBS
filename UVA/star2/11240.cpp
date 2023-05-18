#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >>T;
    while (T--){
        int n;
        cin >>n;
        int fred[n];
        for (int i=0;i<n;i++) cin >>fred[i];
        bool increase = true;
        int ans = 0;
        for (int i=0;i<n;i++){
            if (increase) while (i+1<n && fred[i]<=fred[i+1]) i++;
            else while (i+1<n && fred[i]>=fred[i+1]) i++;
            ans++;
            increase = !increase;
        }
        cout <<ans <<endl;
    }
}