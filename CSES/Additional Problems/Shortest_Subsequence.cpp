/* 
    Greedy Algorithm
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str, ans="";
    set<char> ch;
    cin >>str;
    for (char i: str){
        ch.insert(i);
        if (ch.size()==4){
            ans += i;
            ch.clear();
        }
    }
    for (char i: "AGTC"){
        if (!ch.count(i)){
            ans += i;
            break;
        }
    }
    cout <<ans <<endl;
}