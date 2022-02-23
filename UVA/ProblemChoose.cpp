#include <bits/stdc++.h>

using namespace std;

vector<string> problem;

void print(){
    for (string i: problem) cout <<i <<endl;
    cout <<problem.size() <<endl;
}

void choose(){
    int sz = problem.size();
    srand(time(NULL));
    int ran = rand()%sz;
    cout <<problem[ran] <<endl;
}

void read(){
    string str;
    fstream file;
    file.open("ProblemSet.txt",ios::in);
    while (getline(file,str)) problem.push_back(str);
    random_shuffle(problem.begin(),problem.end());
    file.close();
}

int main(){
    read();
    // print();
    choose();
}