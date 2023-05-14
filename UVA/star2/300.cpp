#include <bits/stdc++.h>

using namespace std;
// Haab: 19month/ 18month 20day/ 19month 5day
// Tzolkin: 13month 20day
map<string,int> haab({
    {"pop", 0}, 
    {"no", 1}, 
    {"zip", 2}, 
    {"zotz", 3}, 
    {"tzec", 4}, 
    {"xul", 5}, 
    {"yoxkin", 6}, 
    {"mol", 7}, 
    {"chen", 8}, 
    {"yax", 9}, 
    {"zac", 10}, 
    {"ceh", 11}, 
    {"mac", 12}, 
    {"kankin", 13}, 
    {"muan", 14}, 
    {"pax", 15}, 
    {"koyab", 16}, 
    {"cumhu", 17},
    {"uayet", 18}
});
map<int,string> tzolkin({
    {0, "ahau"},
    {1, "imix"},
    {2, "ik"},
    {3, "akbal"},
    {4, "kan"},
    {5, "chicchan"},
    {6, "cimi"},
    {7, "manik"},
    {8, "lamat"},
    {9, "muluk"},
    {10, "ok"},
    {11, "chuen"},
    {12, "eb"},
    {13, "ben"},
    {14, "ix"},
    {15, "mem"},
    {16, "cib"},
    {17, "caban"},
    {18, "eznab"},
    {19, "canac"}
});
int main(){
    int n;
    cin >>n;
    cout <<n <<endl;
    for (int cs=0;cs<n;cs++){
        int y, d;
        string m;
        cin >>d;
        getchar();
        cin >>m >>y;
        int tot = y*365 + haab[m]*20 + (d+1);
        // Because tzolkin calendar days are range from 1 to 260, tot divisable by 260 must minus 1
        int ny = tot/260-(tot%260==0), remain = tot%260;
        cout <<(remain%13==0?13:remain%13) <<' ' <<tzolkin[remain%20] <<' ' <<ny <<endl;
    }
}