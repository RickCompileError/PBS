#include <bits/stdc++.h>

using namespace std;

int main(){
    int s;
    vector<int> table{0};
    while (table.back()<=1e8) table.push_back(table.back()+table.size());
    while (cin >>s && s!=0){
        vector<int>::iterator it = upper_bound(table.begin(),table.end(),s);
        cout <<*it-s <<' ' <<it-table.begin() <<endl;
    }
}