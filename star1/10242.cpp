#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x;
    double y;
};

bool equal(Point& a, Point& b){
    return (a.x==b.x) && (a.y==b.y);
}

int main(){
    Point point[4];
    while (cin >>point[0].x >>point[0].y){
        for (int i=1;i<4;i++) cin >>point[i].x >>point[i].y;
        double sumx = 0, sumy = 0;
        for (int i=0;i<4;i++) sumx += point[i].x, sumy += point[i].y;
        int p = -1;
        for (int i=0;i<4 && p==-1;i++)
            for (int j=i+1;j<4 && p==-1;j++)
                if (equal(point[i],point[j])) p = i;
        printf("%.3lf %.3lf\n",sumx-3*point[p].x,sumy-3*point[p].y);
    } 
}