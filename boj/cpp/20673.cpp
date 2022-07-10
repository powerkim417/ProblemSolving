#include <iostream>

using namespace std;


/*
case <= 50/1m && hos <= 10/1m WHITE
hos >= 30 RED
other YELLOW
*/
int main(void){
    int p,q;
    cin>>p>>q;
    if (p<=50 && q<=10) cout<<"White";
    else if (q>=30) cout<<"Red";
    else cout<<"Yellow";
    return 0;
}