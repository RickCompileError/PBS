#include <bits/stdc++.h>

using namespace std;

int xmove[4]{-1,0,1,0};
int ymove[4]{0,1,0,-1};
char D[4]{'W','N','E','S'};

int main(){
    int X, Y, x, y, d;
    char dir;
    string ins;
    map<pair<int,int>,bool> pos;
    cin >>X >>Y;
    while (cin >>x >>y >>dir >>ins){
        bool lost = false;
        if (dir=='W') d = 0;
        else if (dir=='N') d = 1;
        else if (dir=='E') d = 2;
        else d = 3;
        for (char i: ins){
            bool critic = pos[{x,y}];
            if (i=='R') d = (d+1)%4;
            else if (i=='L') d = (d+4-1)%4;
            else x += xmove[d], y += ymove[d];
            if (x<0 || x>X || y<0 || y>Y) lost = true;
            if (critic && lost) x -= xmove[d], y -= ymove[d], lost = false;
            else if (lost) break;
        }
        if (lost){
            cout <<x-xmove[d] <<' ' <<y-ymove[d] <<' ' <<D[d] <<" LOST\n";
            pos[{x-xmove[d],y-ymove[d]}] = true;
        }
        else cout <<x <<' ' <<y <<' ' <<D[d] <<endl; 
    }
}