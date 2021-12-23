#include <bits/stdc++.h>

#define ll long long 

using namespace std;

struct scmp{
    bool operator()(const pair<string,int>& a, const pair<string,int>& b)const {
        return a.first.size()<b.first.size() || (a.first.size()==b.first.size() && a.first<b.first);
    }
};

vector<vector<int>> v;
ll sz;
set<pair<string,int>,scmp> s;

void print(){
    for (vector<int> i: v){
        for (vector<int>::reverse_iterator j=i.rbegin();j!=i.rend();j++) cout <<(*j);
        cout <<endl;
    }
}

void build(){
    v.push_back(vector<int>({1}));
    v.push_back(vector<int>({2}));
    sz = 1;
    while (v[sz++].size()<101){
        v.push_back(vector<int>());
        int carry = 0, sum;
        for (int i=0;i<v[sz-1].size() || carry;i++){
            sum = (i<v[sz-1].size()?v[sz-1][i]:0) + (i<v[sz-2].size()?v[sz-2][i]:0) + carry;
            carry = (sum>=10);
            v[sz].push_back(sum%10);
        }
    }
    for (int i=0;i<v.size();i++){
        string str = "";
        for (vector<int>::reverse_iterator j=v[i].rbegin();j!=v[i].rend();j++) str += ((*j)+48);
        s.insert({str,i});
    }
}

int main(){
    build();
    string a, b;
    while (cin >>a >>b && a!="0" || b!="0"){
        set<pair<string,int>,scmp>::iterator p1 = s.lower_bound({a,0}), p2 = s.upper_bound({b,0});
        // cout <<(*p2).second <<' ' <<(*p1).second <<endl;
        cout <<(*p2).second-(*p1).second <<endl;
    }
}