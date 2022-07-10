#include <iostream>

using namespace std;

int main(void){
    int n; cin>>n;
    string s; cin>>s;
    for (int i=0 ; i<s.size() ; i++){
        if (i%n==0) cout<<s[i];
    }
    return 0;
}