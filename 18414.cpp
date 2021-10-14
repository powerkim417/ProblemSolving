#include <iostream>

using namespace std;

int main(void){
    int x,l,r;
    cin>>x>>l>>r;
    if (x>=r) cout<<r;
    else if (x<=l) cout<<l;
    else cout<<x;
    return 0;
}