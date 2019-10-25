#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int len = s.length();
    for (int i=0 ; i<len ; i++){
        if (s[i]=='?' && s[len-1-i]=='?'){
            s[i] = 'a';
            s[len-1-i] = 'a';
        }
        else if (s[i] == '?'){
            s[i] = s[len-1-i];
        }
    }
    cout<<s;
}