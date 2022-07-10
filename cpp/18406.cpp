#include <iostream>

using namespace std;

int main(void){
    string s;
    cin>>s;
    int sum = 0;
    int len = s.length();
    for (int i=0 ; i<len/2 ; i++){
        sum += s[i]-'0';
    }
    for (int i=len/2 ; i<len ; i++){
        sum -= s[i]-'0';
    }
    if (sum==0) cout<<"LUCKY";
    else cout<<"READY";
    return 0;
}