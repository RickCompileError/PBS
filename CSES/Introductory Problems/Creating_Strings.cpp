#include <bits/stdc++.h>

using namespace std;

set<string> ans;

/* solution 1 */
void recursive(string s, int n){
    for (int i=s.size()-1;i>=n;i--){
        for (int j=i;j<s.size();j++){
            swap(s[i],s[j]);
            ans.insert(s);
            recursive(s,i+1);
            swap(s[i],s[j]);
        }
    }
}

void solution1(){
    string s;
    cin >>s;
    recursive(s,0);
    cout <<ans.size() <<endl;
    for (string i: ans) cout <<i <<endl;
}

/* solution 2 */
void solution2(){
    string s;
    cin >>s;
    sort(s.begin(),s.end());
    int ans{1};
    while (next_permutation(s.begin(),s.end())) ans++;
    cout <<ans <<endl;
    do cout <<s <<endl; while (next_permutation(s.begin(),s.end()));
}

/* solution 3 */
void permute(string s, int l ,int r){
    if (l==r) ans.insert(s);
    else{
        for (int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

void solution3(){
    ans.clear();
    string s;
    cin >>s;
    permute(s,0,s.size()-1);
    cout <<ans.size() <<endl;
    for (string i: ans) cout <<i <<endl;
}

/* solution 4 */
void another_permute(string s, string a){
    if (s.size()==0) ans.insert(a);
    else{
        for (int i=0;i<s.size();i++){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            another_permute(left+right,a+s[i]);
        }
    }
}

void solution4(){
    ans.clear();
    string s;
    cin >>s;
    another_permute(s,"");
    cout <<ans.size() <<endl;
    for (string i: ans) cout <<i <<endl;
}

int main(){
    solution4();
}