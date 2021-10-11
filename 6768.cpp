#include <iostream>

using namespace std;

int main(void){
    int j;
    cin>>j;
    // (j-1) C 3
    if (j<4) cout<<"0";
    else cout<<(j-1)*(j-2)*(j-3)/6;
    return 0;
}