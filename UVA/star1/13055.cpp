#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string q, name;
    cin >>n;
    stack<string> s;
    while (n--){
        cin >>q;
        if (q=="Sleep") cin >>name, s.push(name);
        if (q=="Test") cout <<(s.empty()?"Not in a dream":s.top()) <<endl;
        if (q=="Kick" && !s.empty()) s.pop();
    }
}