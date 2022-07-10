#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int w,h;
    cin>>w>>h;
    double diag = sqrt(w*w+h*h);
    cout<<fixed;
    cout.precision(6);
    cout<<(w+h-diag);
    return 0;
}