#include <iostream>

using namespace std;

string cantor[13] = {};

void add_blank(string& s, int n){
    while (n--) s += " ";
}

string find_cantor(int n){
    if (cantor[n].size()!=0) return cantor[n];
    string ret;
    if (n==0) ret = "-";
    else {
        ret = find_cantor(n-1);
        add_blank(ret, ret.size());
        ret += cantor[n-1];
    }
    cantor[n] = ret;
    return ret;
}

int main(void){
    int n;
    while (cin>>n){
        cout<<find_cantor(n)<<"\n";
    }
    return 0;
}