/* ABCDEFGHIJKLMNOPQRSTUVWXYZ*/
#include <bits/stdc++.h>

using namespace std;

int cs, nkey, nmsg;
string akey, msg;
set<char> sakey;
char ch;

bool deciph(string ans="", int mind=0, int m=0){
    if (mind==msg.size()){
        cout <<ans <<endl;
        return true;
    }

    bool legal = false;
    // rule 1
    if (msg[mind]==' ') legal = deciph(ans+' ', mind+1, m);
    if (legal) return true;

    // rule 2
    ch = (msg[mind]-'A'+26-nkey)%26+'A';
    if (!sakey.count(ch)) legal = deciph(ans+ch, mind+1, m);
    if (legal) return true;

    // rule 3
    if (mind+2>=msg.size()) return false;
    ch = (msg[mind+1]-'A'+26-nkey)%26+'A';
    if (msg[mind]==akey[m] && sakey.count(ch) && msg[mind+2]==akey[(m+1)%akey.size()]) legal = deciph(ans+ch, mind+3, (m+1)%akey.size());
    return legal;
}

int main(){
    bool first = true;
    cin >>cs;
    while (cs--){
        cout <<(first?"":"\n");
        cin >>akey >>nkey >>nmsg;
        getchar();
        sakey.clear();
        for (char i: akey) sakey.insert(i);
        while(nmsg--){
            getline(cin, msg, '\n');
            if (!deciph()) cout <<"error in encryption\n";
        }
        first = false;
    }
}