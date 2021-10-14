#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

// r*r*pi -> 2*r*pi
int main(void){
    long long a;
    cin>>a;
    cout<<fixed;
    cout.precision(6);
    cout<<2*sqrt(a/M_PI)*M_PI;
    return 0;
}