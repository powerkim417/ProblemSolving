#include <iostream>

using namespace std;

int main(void){
    int a,b;
    cin>>a>>b;
    if (a==b) {
        if (a==0) cout<<"Not a moose";
        else cout<<"Even "<<a*2;
    }
    else {
        cout<<"Odd "<<(a>b ? a*2 : b*2);
    }
    return 0;
}