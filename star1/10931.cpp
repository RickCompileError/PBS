#include <bits/stdc++.h>

using namespace std;

int main(){
    int i;
    while (cin >>i && i!=0){
        bitset<32> b(i);
        string trans = b.to_string();
        printf("The parity of %s is %d (mod 2).\n",trans.substr(trans.find_first_not_of('0')).c_str(),b.count());
    }
}