#include <iostream>

using namespace std;

int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    if (a==b && b==c) cout<<"2";
    else {
        if (a*a+b*b==c*c) cout<<"1";
        else if (b*b+c*c==a*a) cout<<"1";
        else if (c*c+a*a==b*b) cout<<"1";
        else cout<<"0";
    }
    return 0;
}