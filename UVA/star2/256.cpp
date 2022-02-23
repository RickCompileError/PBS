#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void build(){
	ans.assign(4,vector<int>());
	for (int n=1,bound=10;n<=4;n++,bound*=10){
		for (int i=0;i<bound;i++)
			for (int j=0;j<bound;j++)
				if ((i+j)*(i+j)==i*bound+j) ans[n-1].push_back(i*bound+j);
	}
}

int main(){
	build();
	int n;
	while (cin >>n){
		for (int i: ans[n/2-1]) cout <<setw(n) <<setfill('0') <<i <<endl;
	}
}
