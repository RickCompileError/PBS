#include <bits/stdc++.h>

using namespace std;

// this function can't satisfy the problem requirement, 
// but instead can judge two string accroding to real string comparison
void for_real_comparison(){
    int m, n, cs = 1;
    while (cin >>m && getchar() && m!=0){
        string s1{""}, s2{""}, tmp;
        while (m--) getline(cin,tmp), s1 += tmp+"\n";
        cin >>n; getchar();
        while (n--) getline(cin,tmp), s2 += tmp+"\n";
        cout <<s1 <<s2;
        bool wrong = false;
        int i = 0, j = 0;
        for (;i<s1.size() && j<s2.size() && !wrong;){
            while (i<s1.size() && isspace(s1[i])) i++;
            while (j<s2.size() && isspace(s2[j])) j++;
            if (i==s1.size() || j==s2.size()) break;
            if (s1[i]==s2[j]) i++, j++;
            else wrong = true;
        }
        if (i<s1.size() || j<s2.size()) wrong = true;
        cout <<"Run #" <<cs++ <<": ";
        if (wrong) cout <<"Wrong Answer\n";
        else if (s1.size()!=s2.size()) cout <<"Presentation Error\n";
        else cout <<"Accepted\n";
    }
}

int main(){
    int m, n, cs = 1;
    while (cin >>m && getchar() && m!=0){
        printf("Run #%d: ",cs++);
        string s1{""}, s2{""}, tmp;
        while (m--) getline(cin,tmp), s1 += tmp+"\n";
        cin >>n, getchar();
        while (n--) getline(cin,tmp), s2 += tmp+"\n";
        if (s1==s2){
            cout <<"Accepted\n";
            continue;
        }
        int i = 0, j = 0;
        bool wrong = false;
        while (!wrong){
            while (i<s1.size() && !isdigit(s1[i])) i++;
            while (j<s2.size() && !isdigit(s2[j])) j++;
            if (i==s1.size() || j==s2.size()) break;
            if (s1[i]!=s2[j]) wrong = true;
            else i++, j++;
        }
        if (wrong || i<s1.size() || j<s2.size()) cout <<"Wrong Answer\n";
        else cout <<"Presentation Error\n";
    }
}