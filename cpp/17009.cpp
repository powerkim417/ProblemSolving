#include <iostream>

using namespace std;

int main(void){
    int a1, a2, a3, b1, b2, b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    if (a1*3 + a2*2 + a3*1 > b1*3 + b2*2 + b3*1) cout<<"A";
    else if (a1*3 + a2*2 + a3*1 < b1*3 + b2*2 + b3*1) cout<<"B";
    else cout<<"T";
}