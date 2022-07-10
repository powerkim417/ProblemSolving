#include <iostream>

using namespace std;

int main(void){
    int x, k;
    cin>>x>>k;
    // (1+1/2+1/4)k = 1.75k
    // (2+1+1/2)k = 3.5k
    // (4+2+1)k = 7k
    if (7*k <= x) cout<<7000*k;
    else if (3.5*k <= x) cout<<3500*k;
    else if (1.75*k <= x) cout<<1750*k;
    else cout<<"0";
    return 0;
}