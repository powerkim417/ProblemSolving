#include <iostream>

using namespace std;

int main(void){
    int a1,c1,e1,a2,c2,e2;
    cin>>a1>>c1>>e1>>a2>>c2>>e2;
    if (c2*2 < c1) cout<<"E";
    else if (c2 < c1) cout<<"D";
    else if (a2*2 < a1) cout<<"C";
    else if (a2 < a1) cout<<"B";
    else cout<<"A";
}