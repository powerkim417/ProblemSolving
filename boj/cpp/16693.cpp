#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

int main(void){
    double a,p1,r,p2;
    cin>>a>>p1>>r>>p2;
    if (p1/a < p2/(r*r*M_PI)) cout<<"Slice of pizza";
    else cout<<"Whole pizza";
    return 0;
}