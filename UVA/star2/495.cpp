#include <bits/stdc++.h>

using namespace std;

/************************* solution 1 *************************/
int bound=1e4;
vector<vector<int>> fib;

void print(vector<int> a){
    int A = a.size();
    cout <<a[A-1];
    for (int i=A-2;i>=0;i--) cout <<setw(4) <<setfill('0') <<a[i];
    cout <<endl;
}

void add(int n){
    int f1 = fib[n-2].size(), f2 = fib[n-1].size(), carry=0;
    for (int i=0;i<max(f1,f2) || carry;i++){
        if (i==fib[n].size()) fib[n].push_back(0);
        fib[n][i] += carry+(i>=f1?0:fib[n-2][i])+(i>=f2?0:fib[n-1][i]);
        carry = fib[n][i]>=bound;
        if (carry) fib[n][i] -= bound;
    }
}

void build(){
    fib.assign(5001,vector<int>());
    fib[0].push_back(0);
    fib[1].push_back(1);
    for (int i=2;i<=5000;i++) add(i);
}

void solution1(){
    build();
    int n;
    while (cin >>n){
        cout <<"The Fibonacci number for " <<n <<" is ";
        print(fib[n]);
    }
}
/************************* solution 1 *************************/

/************************* solution 2 *************************/
const int base = 1e5;
int Fib[5001][2000]{{0},{1}};

void solution2(){
	int n;
	for (int i=2;i<=5000;i++){
		for (int j=0;j<2000;j++){
			Fib[i][j] += Fib[i-1][j] + Fib[i-2][j];
			Fib[i][j+1] = Fib[i][j] / base;
			Fib[i][j] %= base;
		}
	}
	while (cin >>n){
		printf("The Fibonacci number for %d is ",n);
		int pos;
		for (pos=1999;pos>=0;pos--) if (Fib[n][pos]) break;
		if (pos==-1) cout <<0;
		else{
			cout <<Fib[n][pos--];
			for (;pos>=0;pos--) printf("%05d",Fib[n][pos]);
		}
		cout <<endl;
	}
}
/************************* solution 2 *************************/

int main(){
    solution2();
}