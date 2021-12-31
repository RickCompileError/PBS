#include <bits/stdc++.h>

using namespace std;

const int prime = 131071;
vector<int> num;

int main(){
    string str;
    while (cin >>str){
        num.clear();
        do{
            for (int i=0;i<str.size()-1;i++) num.push_back(str[i]-'0');
            if (str[str.size()-1]=='#') break;
            else num.push_back(str[str.size()-1]-'0');
        } while (cin >>str);
        int result = num[0];
        for (int i=1;i<num.size();i++){
            result *= 2;
            result += num[i];
            if (result>=prime) result %= prime;
        }
        cout <<(result?"NO":"YES") <<endl;
    }
}