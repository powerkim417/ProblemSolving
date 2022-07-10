#include <iostream>

using namespace std;

int main(void){
    int n,h,v;
    cin>>n>>h>>v;
    if (h < n-h) h = n-h;
    if (v < n-v) v = n-v;
    cout<<h*v*4;
    return 0;
}