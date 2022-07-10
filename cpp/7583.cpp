#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void){
    string s, token;
    while (1){
        getline(cin, s);
        if (s=="#") return 0;
        istringstream iss(s);
        while (getline(iss, token, ' ')){
            reverse(token.begin()+1, token.end()-1);
            cout<<token<<" ";
        }
        cout<<"\n";
    }
}