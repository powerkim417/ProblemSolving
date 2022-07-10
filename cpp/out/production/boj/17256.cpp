#include <iostream>

using namespace std;

int main(void){
    int ax, ay, az, cx, cy, cz;
    cin>>ax>>ay>>az>>cx>>cy>>cz;
    /*
    cx = az + bx
    cy = ay * by
    cz = ax + bz
    
    bx = cx - az
    by = cy / ay
    bz = cz - ax
    */
    cout<<(cx-az)<<" "<<(cy/ay)<<" "<<(cz-ax);
}