#include <bits/stdc++.h>

using namespace std;

void solution1(){
    int n, x, ans = 0;
    cin >>n;
    bool exist[n+1]{0};
    for (int i=0;i<n;i++){
        cin >>x;
        ans += !(exist[x-1]);
        exist[x] = 1;
    }
    cout <<ans <<endl;
}

void solution2(){
	int n;
	cin >>n;
	int a[n],b[n],round=1;
	for (int i=0;i<n;i++) cin >>a[i];
	for (int i=0;i<n;i++) b[a[i]-1]=i;
	for (int i=1;i<n;i++) if (b[i]<b[i-1]) round++;
	cout <<round <<endl;
}

int main(){
    solution2();
}