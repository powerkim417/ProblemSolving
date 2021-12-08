#include <iostream>

using namespace std;

bool occurred[26];

int main(void){
    string s;
    while (getline(cin, s)){
        if (s=="#") break;
        int answer = 0;
        for (int i=0 ; i<26 ; i++) occurred[i] = false;
        for (char c: s){
            if (c>='A' && c<='Z') occurred[c-'A'] = true;
            if (c>='a' && c<='z') occurred[c-'a'] = true;
        }
        for (int i=0 ; i<26 ; i++) answer += occurred[i];
        cout<<answer<<"\n";
    }
    return 0;
}