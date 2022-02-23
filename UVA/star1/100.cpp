#include <bits/stdc++.h>

using namespace std;

int build[10001];

int algo(int n){
	int count = 0;
	while (true){
		count++;
		if (n==1) return count;
		if (n%2) n = 3*n+1;
		else n = n/2;
	}
}

int main(){
	for (int i=1;i<=10000;i++) build[i] = algo(i);
	int i, j;
	while (cin >>i >>j){
		int ans = -1;
		for (int k=min(i,j);k<=max(i,j);k++) ans = max(ans,algo(k));
		cout <<i <<' ' <<j <<' ' <<ans <<endl;
	}
}