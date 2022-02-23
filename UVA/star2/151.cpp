#include <bits/stdc++.h>

using namespace std;

/*********************** solution 1 ***********************/
int recursive1(int n,int k){
    return n==1?1:(recursive1(n-1,k)+k-1)%n+1;
}

void solve1(){
    int n;
    while (cin >>n && n!=0){
        int k=1;
        while (true){
            int ans = (recursive1(n,k)-((k-1)%n)+n-1)%n+1;
            if (ans==13){
                cout <<k <<endl;
                break;
            }
            k++;
        }
    }
}
/*********************** solution 1 ***********************/

/*********************** solution 2 ***********************/
int ans[101]{0};

int recursive2(int n, int k){
	int pos = (n==1?1:(recursive2(n-1,k)+k-1)%n+1);
	if ((pos-((k-1)%n)+n-1)%n+1==13 && ans[n]==0) ans[n] = k;
	return pos;
}

void build(){
	for (int i=100;i>=13;i--){
		int k = 1;
		while (ans[i]==0) recursive2(i,k++);
	}
}	

void solve2(){
	int n;
	build();
	while (cin >>n && n!=0) cout <<ans[n] <<endl;
}
/*********************** solution 2 ***********************/

/*********************** solution 3 ***********************/
void solve3(){
    int n;
    while (cin >>n && n!=0){
        n--; // position 1 will first remove, so total = n-1;
        int k = 1;
        for (;;k++){
            int pos = 0;
            for (int i=1;i<=n;i++) pos = (pos+k)%i;
            // for the simplicity of the code, set index from 0~n-1, so the answer will be total-1
            if (pos==11) break;
        }
        cout <<k <<endl;
    }
}
/*********************** solution 3 ***********************/

int main(){
    solve3();
}